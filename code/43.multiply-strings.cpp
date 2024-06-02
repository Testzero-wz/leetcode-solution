/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        string s1 = "0";
        string s2 = "";
        int t = 0;
        int i_cnt = 0;
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            int n1 = num1[i] - '0';
            t = 0;
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                int n2 = num2[j] - '0';
                int mul = (n1 * n2 + t);
                s2 += (mul % 10) + '0';
                t = mul / 10;
            }
            if (t != 0)
            {
                s2 += t + '0';
            }
            for (int k = 0; k < i_cnt; k++)
            {
                s2.insert(0, "0");
            }
            s1 = add(s1, s2);
            s2 = "";
            i_cnt++;
        }
        std::reverse(s1.begin(), s1.end());
        return s1;
    }
    string add(string num1, string num2)
    {
        string s = "";
        int i = 0;
        int j = 0;
        int t = 0;
        while (i < num1.length() || j < num2.length())
        {
            int n1 = i < num1.length() ? num1[i] - '0' : 0;
            int n2 = j < num2.length() ? num2[j] - '0' : 0;
            int added = (n1 + n2 + t);
            s += (added % 10) + '0';
            t = added / 10;
            i++;
            j++;
        }
        if (t != 0)
        {
            s += t + '0';
        }
        return s;
    }
};
// @lc code=end
