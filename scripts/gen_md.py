import argparse
import os
import glob
import requests
import json
import re
import time

ENV_KEY_LC_COOKIE = "LC_COOKIE"
WD = os.path.join(os.path.dirname(os.path.abspath(__file__)), "../")
CACHE_FILE_FD = None


def get_req_headers():
    if "csrftoken=" not in os.environ[ENV_KEY_LC_COOKIE]:
        raise Exception("[E] Bad Cookie!")
    user_agent = r"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36"
    csrf_token = [
        kv.split("=")
        for kv in os.environ[ENV_KEY_LC_COOKIE].split(";")
        if "csrftoken" in kv
    ][0][1]
    headers = {
        "User-Agent": user_agent,
        "Connection": "keep-alive",
        "Cookie": os.environ[ENV_KEY_LC_COOKIE],
        "Referer": "https://leetcode.com/problems/two-sum/",
        "X-Csrftoken": csrf_token,
        "Content-Type": "application/json",
    }
    return headers


def lc_get_info(counter):
    if ENV_KEY_LC_COOKIE not in os.environ:
        raise Exception(
            "Leetcode Cookie env variable not set. run command:\n    export LC_COOKIE=<Cookie>"
        )
    url = "https://leetcode.com/api/problems/all/"
    resp = requests.get(url, headers=get_req_headers(), timeout=10)
    raw_info = json.loads(resp.content)
    if "stat_status_pairs" not in raw_info:
        print("Login failed!")
        print(resp.content)
        exit(-1)
    info = {}
    counter.total_cnt = len(raw_info["stat_status_pairs"])
    for item in raw_info["stat_status_pairs"]:
        if item["status"] != "ac":
            continue
        difficulty = item["difficulty"]["level"]
        fronted_id = item["stat"]["frontend_question_id"]
        question_id = item["stat"]["question_id"]
        slug = item["stat"]["question__title_slug"]
        info[str(fronted_id)] = {
            "difficulty": difficulty,
            "slug": slug,
            "question_id": question_id,
        }
    return info


def get_perf(fronted_id, question_id, slug, code, lang):
    global CACHE_FILE_FD
    submit_url = f"https://leetcode.com/problems/{slug}/submit/"
    data = {"question_id": question_id, "lang": lang, "typed_code": code}
    perf_cnt = 0
    max_runtime_beats = 0
    max_memory_beats = 0
    while perf_cnt < 3:
        resp = requests.post(submit_url, headers=get_req_headers(), json=data)
        if resp.status_code == 429:
            print("[W] Rate Limited.")
            time.sleep(3)
            continue
        if resp.status_code != 200:
            raise Exception(f"[E] {resp.status_code} - {resp.content}")
        submission_id = json.loads(resp.content)["submission_id"]
        check_url = f"https://leetcode.com/submissions/detail/{submission_id}/check/"
        while 1:
            time.sleep(3)
            resp = requests.get(check_url, headers=get_req_headers())
            if resp.status_code != 200:
                raise Exception(f"[E] {resp.status_code} - {resp.content}")
            info = json.loads(resp.content)
            print("[Debug] ", info)
            if "status_msg" not in info:
                continue

            if info["status_msg"] != "Accepted":
                return False

            if max_runtime_beats < info["runtime_percentile"]:
                max_runtime_beats = info["runtime_percentile"]
                status_runtime = info["status_runtime"]

            if max_memory_beats < info["memory_percentile"]:
                max_memory_beats = info["memory_percentile"]
                status_memory = info["status_memory"]

            perf_cnt += 1
            break

    perf_info = f"runtime beats {max_runtime_beats:.2f}% ({status_runtime})<br>memory beats {max_memory_beats:.2f}% ({status_memory})"
    CACHE_FILE_FD.write(f"{fronted_id}\n{perf_info}\n")
    CACHE_FILE_FD.flush()
    return perf_info


def read_perf_cache():
    global CACHE_FILE_FD
    cache_path = os.path.join(WD, ".lc_cache")

    CACHE_FILE_FD = open(cache_path, "a+")
    CACHE_FILE_FD.seek(0, 0)
    cache = dict()
    while True:
        id = CACHE_FILE_FD.readline().strip("\n")
        if not id:
            break
        perf_info = CACHE_FILE_FD.readline().strip("\n")
        cache[id] = perf_info
    return cache


class Cnt:
    def __init__(self):
        self.e_cnt = 0
        self.m_cnt = 0
        self.h_cnt = 0
        self.total_cnt = 0

    def sum(self):
        return self.e_cnt + self.m_cnt + self.h_cnt


def main():
    counter = Cnt()
    info = lc_get_info(counter)
    perf_cache = read_perf_cache()
    output_path = os.path.join(WD, "README.MD")
    input_path = os.path.join(WD, "code/*")
    table = "|ID|Question|Solution|Performance|\n|---|---|---|---|\n"
    files = glob.glob(input_path)
    files.sort(key=lambda x: int(os.path.basename(x).split(".")[0]))

    for file in files:
        table += get_row(file, info, perf_cache, counter)
    text = ""
    with open(output_path, "r", encoding="utf-8") as f:
        text = f.read()
        text = text[: text.find("***") + 3] + "\n"
    md = text
    md += f"**Progress:** {counter.sum()}/{counter.total_cnt}\n"
    summary_table = "|Easy|Medium|Hard|\n|--|--|--|\n"
    summary_table += f"|{counter.e_cnt}|{counter.m_cnt}|{counter.h_cnt}|\n"
    md += summary_table
    md += "\n"
    md += table
    with open(output_path, "w", encoding="utf-8") as f:
        f.write(md)
    if CACHE_FILE_FD:
        CACHE_FILE_FD.close()


def get_lang(file_name):
    ext = os.path.splitext(file_name)[1]
    if ext == ".cpp":
        return "cpp"
    elif ext == ".py":
        return "python3"  # no more python2
    elif ext == ".java":
        return "java"
    elif ext == ".c":
        return "c"
    elif ext == ".rs":
        return "rust"
    else:
        raise Exception(f"ext {ext} not support yet")


def get_row(file, info, perf_cache, c):
    file_name = os.path.basename(file)
    with open(file, "r", encoding="utf-8") as f:
        code = f.read()
    m = re.findall("id=([0-9]+)", code)
    if len(m) == 0:
        print("[W]: file not found question fronted_id:", file)
        return ""
    fronted_id = m[0]
    if fronted_id not in info:
        print(f"[W] ID: {fronted_id} not accept yet, skip...")
        return ""

    diff = info[fronted_id]["difficulty"]
    slug = info[fronted_id]["slug"]
    question_id = info[fronted_id]["question_id"]
    if diff == 3:
        diff = "H"
        c.h_cnt += 1
    elif diff == 2:
        diff = "M"
        c.m_cnt += 1
    else:
        diff = "E"
        c.e_cnt += 1
    url = f"https://leetcode.com/problems/{slug}/description"
    question = f"[\\[{diff}\\] {slug}]({url})"
    solution = f"[Link](https://github.com/Testzero-wz/leetcode-solution/blob/master/code/{file_name})"

    # perf three times and save the highest record
    if fronted_id not in perf_cache:
        print(f"[I] now processing {fronted_id}")
        lang = get_lang(file_name)
        performance = get_perf(fronted_id, question_id, slug, code, lang)
    else:
        performance = perf_cache[fronted_id]
    if performance is False:
        print(f"[E] {fronted_id} - {code}")
        return ""
    return f"|{fronted_id}|{question}|{solution}|{performance}|\n"


if __name__ == "__main__":
    main()
