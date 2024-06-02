/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            while (idx < t.length() && t[idx] != c)
                idx++;
            if (idx == t.length())
                return false;
            idx++;
        }
        return true;
    }
};
// @lc code=end
