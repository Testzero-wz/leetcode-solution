/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int p = num1.length() - 1;
        int q = num2.length() - 1;
        int t = 0;
        vector<int> res;
        while (p >= 0 || q >= 0)
        {
            int n1 = p >= 0 ? num1[p] - '0' : 0;
            int n2 = q >= 0 ? num2[q] - '0' : 0;
            int r = (n1 + n2 + t) % 10;
            t = (n1 + n2 + t) / 10;
            res.push_back(r);
            q--;
            p--;
        }
        if (t != 0)
        {
            res.push_back(1);
        }
        string s;
        while (!res.empty())
        {
            s.push_back(res.back() + '0');
            res.pop_back();
        }
        return s;
    }
};
// @lc code=end
