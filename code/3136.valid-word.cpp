/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid Word
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool VOWEL[128];
    char vowel[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    Solution()
    {
        for (auto c : vowel)
        {
            VOWEL[c] = true;
        }
    }
    bool is_vowel(char c)
    {
        return VOWEL[c];
    }
    bool is_consnant(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && !VOWEL[c];
    }
    bool is_digit(char c)
    {
        return c >= '0' && c <= '9';
    }
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;
        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word)
        {
            if (is_vowel(c))
            {
                has_vowel = true;
            }
            else if (is_consnant(c))
            {
                has_consonant = true;
            }
            else if (is_digit(c))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
// @lc code=end
