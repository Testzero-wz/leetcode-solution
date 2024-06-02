/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool is_upper(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    bool detectCapitalUse(string word)
    {
        if (word.length() <= 1)
            return true;
        char first_letter = word[0];
        bool upper_first = is_upper(word[0]);
        // 保证后续一致性
        bool upper_remains = is_upper(word[1]);
        for (int i = 2; i < word.length(); i++)
        {
            bool is_upper_char = is_upper(word[i]);
            if (upper_remains != is_upper_char)
                return false;
        }
        if (upper_remains && !upper_first)
            return false;
        return true;
    }
};
// @lc code=end
