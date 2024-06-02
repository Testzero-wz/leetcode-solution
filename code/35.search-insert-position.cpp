// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int p = 0;
        int q = nums.size() - 1;
        while (p <= q)
        {
            int mid = (p + q) >> 1;
            if (target <= nums[mid])
                q = mid - 1;
            else
                p = mid + 1;
        }
        return p;
    }
};
// @lc code=end
