/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int p = 0;
        int q = 0;
        int sum = 0;
        int min_cnt = nums.size() + 1;
        while (1)
        {
            if (q == nums.size())
                break;
            sum += nums[q];
            if (sum >= target)
            {
                while (p < q && (sum - nums[p] >= target))
                {
                    sum -= nums[p];
                    p++;
                }
                min_cnt = min(q - p + 1, min_cnt);
            }
            q++;
        }
        if (min_cnt == nums.size() + 1)
            return 0;
        return min_cnt;
    }
};
// @lc code=end
