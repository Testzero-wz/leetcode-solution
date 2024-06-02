/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int MAX = 0x7fffff;
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int top;
        int left;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                top = i - 1 >= 0 ? grid[i - 1][j] : MAX;
                left = j - 1 >= 0 ? grid[i][j - 1] : MAX;
                grid[i][j] += min(top, left);
            }
        }
        return grid[n - 1][m - 1];
    }
};
// @lc code=end
