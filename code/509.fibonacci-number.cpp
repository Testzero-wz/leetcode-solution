/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int n1 = 1;
        int n2 = 1;
        int cnt;
        for (int i = 3; i <= n; i++)
        {
            cnt = n1 + n2;
            n1 = n2;
            n2 = cnt;
        }
        return cnt;
    }
};
// @lc code=end
