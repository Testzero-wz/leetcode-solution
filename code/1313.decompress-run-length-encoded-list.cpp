/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i + 1 < nums.size(); i += 2)
        {
            int freq = nums[i];
            int num = nums[i + 1];
            while (freq--)
                res.push_back(num);
        }
        return res;
    }
};
// @lc code=end
