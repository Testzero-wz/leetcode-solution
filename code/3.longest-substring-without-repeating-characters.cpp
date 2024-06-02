/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int p = 0;
        bool table[128];
        int max_cnt = 0;
        for (int i = 0; i < 128; i++)
            table[i] = false;
        int i = 0;
        for (; i < s.length(); i++)
        {
            char c = s[i];
            if (!table[c])
            {
                table[c] = true;
            }
            else
            {
                // same
                max_cnt = max(max_cnt, i - p);
                while (s[p] != c)
                {
                    table[s[p]] = false;
                    p++;
                }
                p++;
            }
        }
        max_cnt = max(max_cnt, i - p);
        return max_cnt;
    }
};
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         char prevs[128];
//         char nexts[128];
//         for (int i = 0; i < 128; i++)
//         {
//             prevs[i] = 0;
//             nexts[i] = 0;
//         }
//         bool hits[128] = {false};
//         int max_len = 0;
//         int cur_len = 0;
//         char last = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             char c = s[i];
//             if (!hits[c])
//             {
//                 hits[c] = true;
//                 prevs[c] = last;
//                 nexts[c] = 0;
//                 nexts[last] = c;
//                 last = c;
//                 cur_len++;
//                 max_len = cur_len > max_len ? cur_len : max_len;
//             }
//             else
//             {
//                 // already in prev substring
//                 // unlink
//                 char next = nexts[c];
//                 if (next != 0)
//                 {
//                     prevs[next] = 0;
//                 }
//                 char prev = prevs[c];
//                 while (prev != 0)
//                 {
//                     char tmp = prevs[prev];
//                     prevs[prev] = 0;
//                     nexts[prev] = 0;
//                     hits[prev] = false;
//                     cur_len--;
//                     prev = tmp;
//                 }
//                 if (last == c)
//                 {
//                     prevs[c] = 0;
//                 }
//                 else
//                 {
//                     prevs[c] = last;
//                     last = c;
//                 }
//                 if (prevs[c] != 0)
//                 {
//                     nexts[prevs[c]] = c;
//                 }
//                 nexts[c] = 0;
//             }
//         }
//         return max_len;
//     }
// };
// @lc code=end
