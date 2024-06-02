/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        vector<string> strs;
        vector<long long> unit_lens;
        string tmp = "";
        int total_len = 0;
        int str_len = 0;
        k -= 1;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (!(c >= '2' && c <= '9'))
            {
                tmp.push_back(c);
            }
            if ((c >= '2' && c <= '9') || i == s.length() - 1)
            {
                int d = c - '0';
                if (!(c >= '2' && c <= '9'))
                    d = 1;
                long long unit_len = total_len + tmp.length();
                unit_lens.push_back(unit_len);
                total_len = unit_len * d;
                strs.push_back(tmp);
                tmp = "";
                if (k < total_len)
                {
                    while (1)
                    {
                        int unit_len = unit_lens.back();
                        unit_lens.pop_back();
                        k %= unit_len;
                        string cur_str = strs.back();
                        strs.pop_back();
                        int last_total_len = unit_len - cur_str.length();
                        if (k < last_total_len)
                        {
                            // continue
                        }
                        else
                        {
                            // is cur_str
                            k -= last_total_len;
                            // return cur_str;
                            return string(1, cur_str[k]);
                        }
                    }
                }
            }
        }

        return "";
    }
};
// @lc code=end
