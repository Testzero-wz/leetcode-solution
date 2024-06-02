/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num < 10)
            return num;
        int res = num % 9;
        return res == 0 ? 9 : res;
    }
};
// @lc code=end
