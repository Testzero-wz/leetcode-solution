/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int p = 0;
        int q = s.size() - 1;
        while (1)
        {
            while (p < s.length() && !is_vowels(s[p]))
                p++;

            while (q >= 0 && !is_vowels(s[q]))
                q--;

            if (q <= p)
            {
                break;
            }
            // swap
            int tmp = s[p];
            s[p] = s[q];
            s[q] = tmp;
            // move ptr
            p++;
            q--;
        }
        return s;
    }

    bool is_vowels(char c)
    {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};
// @lc code=end
