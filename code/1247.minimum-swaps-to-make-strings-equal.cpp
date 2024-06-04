/*
 * @lc app=leetcode id=1247 lang=cpp
 *
 * [1247] Minimum Swaps to Make Strings Equal
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int length = s1.length();
        char c1;
        char c2;
        bool x_y = false;
        bool y_x = false;
        int step = 0;
        for (int i = 0; i < length; i++)
        {
            c1 = s1[i];
            c2 = s2[i];
            if (c1 == c2)
                continue;
            // x_y
            if (c1 == 'x')
            {
                if (!x_y)
                    x_y = true;
                else
                {
                    x_y = false;
                    step++;
                }
            }
            else
            {
                // y_x
                if (!y_x)
                    y_x = true;
                else
                {
                    y_x = false;
                    step++;
                }
            }
        }
        if (y_x == x_y)
        {
            if (x_y)
                step += 2;
        }
        else
            return -1;
        return step;
    }
};
// @lc code=end
