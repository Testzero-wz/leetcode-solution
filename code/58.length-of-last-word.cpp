/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int cnt = 0;
        bool found = false;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            char c = *it;
            if (c == ' ')
            {
                if (found)
                    break;
                continue;
            }
            if (c != ' ')
            {
                found = true;
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
