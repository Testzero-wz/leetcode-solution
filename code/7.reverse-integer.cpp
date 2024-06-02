/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
// @lc code=start
class Solution
{
public:
    int MAX = 2147483647;
    int D10 = 2147483647 / 10;
    int reverse(int x)
    {
        if (x == -2147483648)
        {
            return 0;
        }
        int neg_flag = x < 0;
        x = abs(x);
        int num = 0;
        while (1)
        {
            if (x == 0)
            {
                break;
            }
            int n = x % 10;
            x /= 10;
            if (neg_flag)
            {
                if (num > D10)
                {
                    return 0;
                }
                num = num * 10;
                if ((MAX - num) < n - 1)
                {
                    return 0;
                }
                num += n;
            }
            else
            {
                if (num > D10)
                {
                    return 0;
                }
                num = num * 10;
                if (MAX - num < n)
                {
                    return 0;
                }
                num += n;
            }
        }
        if (neg_flag)
        {
            return -num;
        }
        return num;
    }
};
// @lc code=end
