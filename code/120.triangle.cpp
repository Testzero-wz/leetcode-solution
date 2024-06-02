/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
        {
            return triangle[0][0];
        }
        int min_path_sum = 0xffff;
        int pos = 0;
        for (int t = 1; t < triangle.size(); t++)
        {
            vector<int> &cur_layer = triangle[t];
            vector<int> &upper_layer = triangle[t-1];
            for (int i = 0; i < cur_layer.size(); i++)
            {
                if (i == 0)
                {
                    cur_layer[i] += upper_layer[i];
                }
                else if (i == cur_layer.size() - 1)
                {
                    cur_layer[i] += upper_layer[i - 1];
                }
                else
                {
                    cur_layer[i] += min(upper_layer[i], upper_layer[i - 1]);
                }
                if (t == triangle.size() - 1)
                {
                    min_path_sum = min(min_path_sum, cur_layer[i]);
                }
            }
        }
        return min_path_sum;
    }
};
// @lc code=end
