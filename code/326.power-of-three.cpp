/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        long long s = 1;
        long long r = n;
        while (s < r)
            s *= 3;
        return s == r;
    }
};
// @lc code=end
