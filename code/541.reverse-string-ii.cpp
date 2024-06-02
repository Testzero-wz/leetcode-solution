/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */
#include <string>
#include <sstream>
using namespace std;
// @lc code=start
class Solution
{
public:
    void rev(string &s, int start, int end, stringstream &ss)
    {
        for (int i = end - 1; i >= start; i--)
        {
            if (i < s.length())
                ss << s[i];
        }
        return;
    }
    string reverseStr(string s, int k)
    {
        int idx = 0;
        stringstream ss;
        while (1)
        {
            bool reverse_flag = (idx / k) % 2 == 0;
            if (reverse_flag)
            {
                rev(s, idx, idx + k, ss);
                idx += k;
            }
            else
            {
                int max_idx = idx + k;
                for (; idx < max_idx; idx++)
                {
                    if (idx < s.length())
                        ss << s[idx];
                }
            }
            if (idx >= s.length())
                break;
        }
        return ss.str();
    }
};
// @lc code=end
