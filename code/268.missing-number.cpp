/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int p = 0;
        int tmp;
        int val;
        int n = nums.size();
        int n_val = -1;
        int last_ptr = n;
        while (p < nums.size())
        {
            val = nums[p];
            while (val != p)
            {
                if (val == -1)
                {
                    last_ptr = p;
                    break;
                }
                else if (val == n)
                {
                    tmp = n_val;
                    n_val = n;
                }
                else
                {
                    tmp = nums[val];
                    nums[val] = val;
                }
                val = tmp;
            }
            nums[p] = val;
            p++;
        }
        return last_ptr;
    }
};
// @lc code=end
