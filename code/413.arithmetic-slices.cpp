/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */
#include <cmath>
// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return 0;
        }
        int last_diff = -1;
        int cnt = 0;
        int total_cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int n1 = nums[i];
            int n2 = nums[i + 1];
            int diff = abs(n1 - n2);
            if (last_diff == -1)
            {
                last_diff = diff;
                cnt++;
            }
            else
            {
                if (last_diff == diff)
                {
                    cnt++;
                }
                else
                {
                    if (cnt >= 2)
                    {
                        total_cnt += (cnt * (cnt - 1)) / 2;
                    }
                    cnt = 0;
                    last_diff == -1;
                }
            }
        }
        if (cnt >= 2)
        {
            total_cnt += (cnt * (cnt - 1)) / 2;
        }
        return total_cnt;
    }
};
// @lc code=end
