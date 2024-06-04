/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int f[40];
    Solution()
    {
        for (int i = 1; i < 40; i++)
            f[i] = fib(i);
    }
    int numDecodings(string s)
    {
        int cnt = 0;
        int res = 1;
        char last = 'a';
        for (auto c : s)
        {
            if (c == '1' || c == '2')
                cnt++;
            else
            {
                if (c == '0')
                {
                    if (last != '1' && last != '2')
                        return 0;
                    cnt--;
                }
                else if (last == '2' && c - '0' > 6)
                {
                    // do nothing
                }
                else
                    cnt++;
                if (cnt > 1)
                    res *= f[cnt];
                cnt = 0;
            }
            last = c;
        }
        if (cnt > 1)
            res *= fib(cnt);
        return res;
    }
    int fib(int n)
    {
        if (n <= 2)
            return n;
        int n1 = 1;
        int n2 = 2;
        int cur;
        for (int i = 3; i <= n; i++)
        {
            cur = n1 + n2;
            n1 = n2;
            n2 = cur;
        }
        return cur;
    }
};
// @lc code=end
