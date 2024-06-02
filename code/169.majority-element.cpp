/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cur_num = 0;
        int cnt = 0;
        for (auto num : nums)
        {
            if (cnt == 0)
            {
                cur_num = num;
            }
            if (cur_num == num)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return cur_num;
    }
};
// @lc code=end
