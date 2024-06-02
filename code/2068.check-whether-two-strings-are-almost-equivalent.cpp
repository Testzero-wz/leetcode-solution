/*
 * @lc app=leetcode id=2068 lang=cpp
 *
 * [2068] Check Whether Two Strings are Almost Equivalent
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int table[26];
    bool checkAlmostEquivalent(string word1, string word2)
    {
        for (int i = 0; i < 26; i++)
        {
            table[i] = 0;
        }
        for (int i = 0; i < word1.size(); i++)
        {
            table[word1[i] - 'a']++;
            table[word2[i] - 'a']--;
        }
        int tmp;
        for (int i = 0; i < 26; i++)
        {
            tmp = table[i];
            if (tmp > 3 || tmp < -3)
                return false;
        }
        return true;
    }
};
// @lc code=end
