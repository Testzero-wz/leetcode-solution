/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for(auto n: nums){
            t ^= n;
        }
        return t;
    }
};
// @lc code=end

