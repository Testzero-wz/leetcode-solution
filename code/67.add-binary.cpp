/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <sstream>
#include <string>
using namespace std;
class Solution
{
public:
    int c2i(char c)
    {
        return c - '0';
    }
    string addBinary(string a, string b)
    {
        std::stringstream ss;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int t = 0;
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? c2i(a[i]) : 0;
            int n2 = j >= 0 ? c2i(b[j]) : 0;
            int n3 = (n1 + n2 + t) % 2;
            t = (n1 + n2 + t) / 2;
            ss << (char)(n3 + '0');
            i--;
            j--;
        }
        if (t != 0)
        {
            ss << '1';
        }
        std::stringstream res;
        string tmp = ss.str();
        for (int i = tmp.length() - 1; i >= 0; i--)
        {
            res << tmp[i];
        }
        return res.str();
    }
};
// @lc code=end
