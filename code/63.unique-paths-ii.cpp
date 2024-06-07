/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int low[m];
        for (int i = 0; i < m; i++)
            low[i] = 0;
        low[0] = 1;
        int left;
        int top;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    low[j] = 0;
                    continue;
                }
                top = low[j];
                left = j > 0 ? low[j - 1] : 0;
                low[j] = top + left;
            }
        }
        return low[m - 1];
    }
};
// @lc code=end
