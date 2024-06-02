/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int idx = 0;
        while (1)
        {
            char c = -1;
            for (auto str : strs)
            {
                if (idx >= str.length())
                {
                    return str;
                }
                if (c == -1)
                {
                    c = str[idx];
                    continue;
                }
                if (c != str[idx])
                {
                    return str.substr(0, idx);
                }
            }
            idx++;
        }
        return strs[0];
    }
};
// @lc code=end
