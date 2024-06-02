/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> buf;
        f(1, n, k, buf, res);
        return res;
    }

    void f(int s, int n, int k, vector<int> &buf, vector<vector<int>> &res)
    {
        if (k == 0)
        {
            res.push_back(buf);
        }
        for (int i = s; i <= n; i++)
        {
            buf.push_back(i);
            f(i + 1, n, k - 1, buf, res);
            buf.pop_back();
        }
    }
};
// @lc code=end
