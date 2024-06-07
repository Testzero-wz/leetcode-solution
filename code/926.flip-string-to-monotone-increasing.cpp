/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int last_0 = 0;
        int last_1 = 0;
        bool flip_to_0;
        for (auto &c : s)
        {
            flip_to_0 = c == '1';
            last_1 = min(last_0, last_1);
            last_1 += !flip_to_0;
            last_0 += flip_to_0;
        }
        return min(last_0, last_1);
    }
};
// @lc code=end
