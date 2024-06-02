/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool is_alnum(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool is_equal(char c1, char c2)
    {
        return mapping(c1) == mapping(c2);
    }

    int mapping(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return c - '0';
        }
        else
        {
            return (c >= 'a' ? c - 'a' : c - 'A') + 10;
        }
    }
    bool isPalindrome(string s)
    {
        int p = 0;
        int q = s.length() - 1;
        while (1)
        {
            while (p < s.length() && !is_alnum(s[p]))
                p++;

            if (p == s.length())
                return true;

            while (q >= 0 && !is_alnum(s[q]))
                q--;

            if (q == -1)
                return true;

            if (!is_equal(s[p], s[q]))
                return false;

            if (p >= q)
                return true;
            p++;
            q--;
        }
        return true;
    }
};
// @lc code=end
