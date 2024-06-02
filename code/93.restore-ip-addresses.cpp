/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    char get_char(string &s, int sp)
    {
        if (sp < s.length())
        {
            return s[sp];
        }
        return -1;
    }

    int get_num(string &s, int sp)
    {
        int i = 0;
        int num = 0;
        for (; i < 3; i++)
        {
            char c = get_char(s, sp + i);
            if (c == -1)
            {
                break;
            }
            if (i == 0 && c == '0')
            {
                return 1;
            }
            num = num * 10 + c - '0';
            if (num >= 256)
            {
                break;
            }
        }
        return i;
    }

    vector<string> restoreIpAddresses(string s)
    {
        return f(s, 0, 0);
    }

    vector<string> f(string &s, int sp, int ord)
    {
        vector<string> res = vector<string>();
        // short path
        int max_idx = get_num(s, sp);
        if (max_idx <= 0)
        {
            return res;
        }
        if (ord == 3)
        {
            if (s.length() - sp > 3)
            {
                return res;
            }

            if (max_idx + sp != s.length())
            {
                return res;
            }
            res.push_back(s.substr(sp));
        }
        else
        {
            for (int i = 1; i <= max_idx; i++)
            {
                string cur_num_str = s.substr(sp, i);
                vector<string> v = f(s, sp + i, ord + 1);
                if (v.size() == 0)
                {
                    continue;
                }
                for (auto str : v)
                {
                    res.push_back(cur_num_str + "." + str);
                }
            }
        }
        return res;
    }
};
// @lc code=end
