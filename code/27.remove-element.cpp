/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int p = 0;
        int q = 0;
        int v;
        int n = nums.size();
        while (1)
        {
            while (q < n && (v = nums[q]) == val)
                q++;
            if (q == n)
                break;
            nums[p] = v;
            p++;
            q++;
        }
        return p;
    }
};
// @lc code=end
