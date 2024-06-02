/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int l[501];
    int h[501];
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length();
        int l2 = word2.length();
        if (l1 == 0 || l2 == 0)
            return max(l1, l2);
        int *low = l;
        int *high = h;
        bool exchange = false;
        // init
        for (int j = 0; j <= l2; j++)
            low[j] = j;
        // dp
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                high[0] = i;
                if (word1[i - 1] == word2[j - 1])
                {
                    high[j] = low[j - 1];
                }
                else
                {
                    int tmp = min(high[j - 1], low[j - 1]);
                    high[j] = min(tmp, low[j]) + 1;
                }
            }
            exchange = true;
            int *tmp_ptr = low;
            low = high;
            high = tmp_ptr;
        }
        return low[l2];
    }
};
// @lc code=end
