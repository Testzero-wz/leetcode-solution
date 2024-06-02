/*
 * @lc app=leetcode id=3131 lang=cpp
 *
 * [3131] Find the Integer Added to Array I
 */

// @lc code=start
class Solution
{
public:
    int find_max(vector<int> &nums)
    {
        int max_int = -1;
        for (auto i : nums)
        {
            if (max_int < i)
                max_int = i;
        }
        return max_int;
    }
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        return find_max(nums2) - find_max(nums1);
    }
};
// @lc code=end
