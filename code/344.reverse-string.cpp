/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int p = 0;
        int q = s.size() - 1;
        while (1)
        {
            if (q <= p)
            {
                break;
            }
            // swap
            int tmp = s[p];
            s[p] = s[q];
            s[q] = tmp;
            // move ptr
            p++;
            q--;
        }
        return;
    }
};
// @lc code=end
