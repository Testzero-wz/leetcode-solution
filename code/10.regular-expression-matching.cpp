/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
int MAX = 100;
typedef struct cond
{
    char c;
    int min_cnt;
    int max_cnt;
} cond;

class Solution
{
public:
    char next_char(string &p, int pos)
    {
        if (pos < p.length())
        {
            return p[pos];
        }
        return -1;
    }

    char get_char(string &p, int pos)
    {
        char c = next_char(p, pos);
        if (c == -1)
        {
            return -1;
        }
        if ((c >= 'a' && c <= 'z') || c == '$' || c == '.')
        {
            return c;
        }
        return -1;
    }

    int get_mod(string &p, int pos)
    {
        // stupid test case
        // "a***abc"
        int cnt = 0;
        while (1)
        {
            char c = next_char(p, pos);
            if (c == -1)
            {
                // error
                return -1;
            }
            if (c == '*')
            {
                // *
                cnt++;
                pos++;
                continue;
            }
            // not *
            return cnt;
        }
    }

    vector<cond *> compile_regex(string p)
    {
        int pos = 0;
        string pat = p + "$";
        vector<cond *> conds = vector<cond *>();
        while (1)
        {
            char c = get_char(pat, pos);
            if (c == -1)
            {
                break;
            }
            pos++;
            int read_star_num = get_mod(pat, pos);
            bool modi = false;
            if (read_star_num > 0)
            {
                modi = true;
                pos += read_star_num;
            }
            cond *cur_cond = new cond{
                c,
                modi ? 0 : 1,
                modi ? MAX : 1,
            };
            if (!conds.empty())
            {
                // try to merge adj cond that has the some char
                cond *last_cond = conds.back();
                if (last_cond->c == c)
                {
                    last_cond->min_cnt += cur_cond->min_cnt;
                    last_cond->max_cnt = min(MAX, cur_cond->max_cnt + last_cond->max_cnt);
                }
                else
                {
                    conds.push_back(cur_cond);
                }
            }
            else
            {
                conds.push_back(cur_cond);
            }
        }
        return conds;
    }

    bool match(string &s, int sp, vector<cond *> &conds, int top)
    {
        cond *cur_cond = conds[top];
        top++;
        for (int i = cur_cond->min_cnt; i <= cur_cond->max_cnt; i++)
        {
            int tmp_sp = sp;
            if (i != 0)
            {
                int should_match_char_num = i;
                while (should_match_char_num--)
                {
                    char c = get_char(s, sp);
                    if (c == -1)
                    {
                        return false;
                    }
                    sp++;
                    if (cur_cond->c != '.' && cur_cond->c != c)
                    {
                        return false;
                    }
                }
            }
            if (cur_cond->c == '$')
            {
                return true;
            }
            if (match(s, sp, conds, top))
            {
                return true;
            }
            sp = tmp_sp;
        }
        return false;
    }

    bool isMatch(string s, string p)
    {
        int top = 0;
        int sp = 0;
        s += "$";
        vector<cond *> conds = compile_regex(p);
        return match(s, sp, conds, top);
    }
};
// @lc code=end
