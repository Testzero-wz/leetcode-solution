/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    int table[26];
    int c2i(char c)
    {
        return c - 'a';
    }
    bool isAnagram(string s, string t)
    {
        for (int i = 0; i < 26; i++)
            table[i] = 0;
        for (auto c : s)
        {
            table[c2i(c)]++;
        }
        for (auto c : t)
        {
            table[c2i(c)]--;
        }
        int res = true;
        for (int i = 0; i < 26; i++)
        {
            if (table[i] != 0)
            {
                res = false;
                table[i] = 0;
            }
        }
        return res;
    }
};
// @lc code=end
