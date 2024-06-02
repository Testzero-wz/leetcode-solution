/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int f_n = nums[0];
        int max_sum = f_n;
        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];
            f_n = f_n > 0 ? f_n + num : num;
            max_sum = f_n > max_sum ? f_n : max_sum;
        }
        return max_sum;
    }
};
// @lc code=end
