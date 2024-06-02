/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int t = 1;
        int r;
        int n;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            r = digits[i] + t;
            t = r / 10;
            n = r % 10;
            digits[i] = n;
        }
        if (t == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
