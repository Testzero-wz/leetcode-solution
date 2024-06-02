/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution
{
public:
    int MAX = 1 << 16;
    bool isPerfectSquare(int num)
    {
        long long _num = num;
        long long left = 1;
        long long right = _num;
        long long mid;
        long long res;
        while (1)
        {
            if (left > right)
                return false;
            mid = (left + right) >> 1;
            if (mid > MAX)
            {
                right = mid - 1;
                continue;
            }
            long long res = (long long)mid * mid;
            if (res > _num)
            {
                right = mid - 1;
                continue;
            }
            else if (res < _num)
            {
                left = mid + 1;
                continue;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
