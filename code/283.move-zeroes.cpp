/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int idx = 0;
        int p = 0;
        while (1)
        {
            while (p < nums.size() && nums[p] == 0)
                p++;
            if (p >= nums.size())
                break;
            nums[idx] = nums[p];
            p++;
            idx++;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
        return;
    }
};
// @lc code=end
