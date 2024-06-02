/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> s;
        vector<int> res;
        int another;
        int num;
        for (int i = 0; i < nums.size(); i++)
        {
            num = nums[i];
            another = target - num;
            if (s.find(another) != s.end())
            {
                res.push_back(s[another]);
                res.push_back(i);
                break;
            }
            s[num] = i;
        }
        return res;
    }
};
// @lc co\de=end
