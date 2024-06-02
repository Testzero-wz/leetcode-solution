/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <vector>
#include <string>
#include <map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        int table[26];
        for (auto s : strs)
        {
            for (int i = 0; i < 26; i++)
            {
                table[i] = 0;
            }
            string key = get_count_string(s, table);
            if (m.find(key) == m.end())
                m[key] = vector<string>();
            m[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }

    string get_count_string(string &s, int table[26])
    {
        for (auto c : s)
        {
            table[c - 'a']++;
        }
        char num_str[80];
        string res = "";
        for (int i = 0; i < 26; i++)
        {
            sprintf(num_str, "%d|", table[i]);
            res += num_str;
        }
        return res;
    }
};
// @lc code=end
