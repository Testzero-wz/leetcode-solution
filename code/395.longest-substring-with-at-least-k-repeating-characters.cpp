/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int c2i(char c)
    {
        return c - 'a';
    }
    int longestSubstring(string s, int k)
    {
        int t[26];
        int max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int cur_len = 0;
            int type = 0;
            for (int i = 0; i < 26; i++)
            {
                t[i] = 0;
            }
            for (int j = i; j < s.length(); j++)
            {
                int idx = c2i(s[j]);
                if (t[idx] == 0)
                {
                    type += 1;
                }
                t[idx]++;
                if (t[idx] == k)
                {
                    type -= 1;
                }
                if (type == 0)
                {
                    cur_len = j - i + 1;
                    max_len = max(cur_len, max_len);
                }
            }
        }
        return max_len;
    }
};
// @lc code=end
