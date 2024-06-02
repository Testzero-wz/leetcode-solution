/*
 * @lc app=leetcode id=2784 lang=cpp
 *
 * [2784] Check if Array is Good
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return false;
        int p = 1;
        int n = nums.size() - 1;
        int tmp;
        int val;
        while (p < nums.size())
        {
            val = nums[p];
            while (val != p)
            {
                if (!(val >= 0 && val <= n))
                    return false;
                tmp = nums[val];
                // place target
                if (val == n)
                {
                    if (nums[0] == n && nums[n] == n)
                        return false;
                    if (nums[n] != n)
                    {
                        tmp = nums[n];
                        nums[n] = n;
                        val = tmp;
                    }
                    else
                    {
                        tmp = nums[0];
                        nums[0] = n;
                        val = tmp;
                    }
                }
                else
                {
                    // already equal
                    if (tmp == val)
                        return false;
                    nums[val] = val;
                    val = tmp;
                }
            }
            p++;
        }
        return nums[0] == n;
    }
};
// @lc code=end
