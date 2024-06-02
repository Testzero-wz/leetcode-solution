/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return C(min(n, m) - 1, m - 1 + n - 1);
    }

    long long C(long long m, long long n)
    {
        long long sum = 1;
        for (int i = 1; i <= m; i++)
        {
            long long t = (n - i + 1);
            sum = sum * t / i;
        }
        return sum;
    }
};
// @lc code=end
