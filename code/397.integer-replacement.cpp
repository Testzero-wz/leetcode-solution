/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution
{
public:
    int integerReplacement(int n)
    {
        return (int)f(n);
    }
    long long f(long long n)
    {
        switch (n)
        {
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
        case 4:
            return 2;
        }
        if (n % 2 == 0)
        {
            return f(n / 2) + 1;
        }
        else
        {
            return min(f(n + 1) + 1, f(n - 1) + 1);
        }
    }
};
// @lc code=end
