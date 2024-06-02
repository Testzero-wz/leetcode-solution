/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i <= nums.size(); i++)
            c(0, 0, i, nums, tmp, res);
        return res;
    }

    void c(int idx, int cur_level, int target_level, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res)
    {
        if (target_level == cur_level)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            c(i + 1, cur_level + 1, target_level, nums, tmp, res);
            tmp.pop_back();
        }
    }
};
// @lc code=end
