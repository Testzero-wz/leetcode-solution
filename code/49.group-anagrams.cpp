/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        // vector<int> groups;
        char table[26];
        int group_id = -1;
        for (auto &s : strs)
        {
            for (int i = 0; i < 26; i++)
                table[i] = 0;
            string key = get_count_string(s, table);
            int cur_gid;
            if (map.find(key) == map.end())
            {
                group_id++;
                res.emplace_back(vector<string>());
                map[key] = group_id;
                cur_gid = group_id;
            }
            else
                cur_gid = map[key];
            res[cur_gid].emplace_back(s);
        }
        return res;
    }

    string get_count_string(string &s, char table[26])
    {
        for (auto c : s)
            table[c - 'a']++;
        return string(table, table + 26);
    }
};
// @lc code=end
