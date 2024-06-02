/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        vector<char> chars;
        while (x)
        {
            chars.push_back(x % 10);
            x /= 10;
        }
        int p = 0;
        int q = chars.size() - 1;
        while (p <= q)
        {
            if (chars[p] != chars[q])
                return false;
            p++;
            q--;
        }
        return true;
    }
};
// @lc code=end
