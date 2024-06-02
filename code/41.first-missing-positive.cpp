// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == 1)
                return 2;
            else
                return 1;
        }
        int p = 0;
        int size = nums.size();
        while (p < size)
        {
            int cur_num = nums[p];
            if (cur_num > 0 && cur_num < size && cur_num != (p + 1))
            {
                nums[p] = -1;
                int q = cur_num - 1;
                while (1)
                {
                    if (q < 0 || q >= size || (q + 1) == nums[q])
                        break;
                    int record = nums[q];
                    nums[q] = q + 1;
                    q = record - 1;
                }
            }
            p++;
        }
        int res = nums.size() + 1;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != i + 1)
            {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
