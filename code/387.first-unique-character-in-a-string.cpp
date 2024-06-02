/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int table[26];
        for (int i = 0; i < 26; i++)
            table[i] = -1;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            // already repeat
            if (table[idx] == -2)
                continue;
            // not emerge yet
            if (table[idx] == -1)
            {
                table[idx] = i;
            }
            else
            {
                // repeat
                table[idx] = -2;
            }
        }
        int idx = -1;
        for (int i = 0; i < 26; i++)
        {
            if (table[i] >= 0)
            {
                if (idx == -1)
                    idx = 0xffffff;
                idx = min<int>(idx, table[i]);
            }
        }
        return idx;
    }
};
// @lc code=end
