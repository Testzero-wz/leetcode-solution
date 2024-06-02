/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<long long> table;
    Solution()
    {
        int mul = 2;
        table.push_back(0);
        table.push_back(10);
        long long num = 90;
        while (1)
        {
            long long res = table.back() + num * mul;
            table.push_back(res);
            if (res > 2147483647)
                break;
            num = num * 10;
            mul++;
        }
    }
    int findNthDigit(int n)
    {
        if (n < 10)
        {
            return n;
        }
        auto it = upper_bound(table.begin(), table.end(), n);
        int mul = it - table.begin();
        n -= table[mul - 1];
        int idx = n / mul;
        int r = n % mul;
        int num = 1;
        int tmp_mul = mul - 1;
        while (tmp_mul--)
            num *= 10;
        int t = mul - r - 1;
        int v = num + idx;
        while (t--)
            v /= 10;
        return v % 10;
    }
};
// @lc code=end
