/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        bool neg = num < 0;
        num = abs(num);
        int base = 7;
        int tmp;
        vector<char> res;
        while (num)
        {
            tmp = num % base;
            res.push_back(tmp + '0');
            num /= base;
        }
        if (neg)
            res.push_back('-');

        reverse(res.begin(), res.end());
        return string(res.begin(), res.end());
    }
};
// @lc code=end
