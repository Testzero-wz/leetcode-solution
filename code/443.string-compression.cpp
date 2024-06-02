/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        char cur = -1;
        int group_length = 0;
        int ptr = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            char c = chars[i];
            if (group_length == 0 || cur == c)
            {
                group_length++;
            }
            else
            {
                // cur != c
                chars[ptr++] = cur;
                string num_str = "";
                if (group_length > 1)
                {
                    while (group_length)
                    {
                        num_str += group_length % 10 + '0';
                        group_length /= 10;
                    }
                }
                for (int j = num_str.length() - 1; j >= 0; j--)
                {
                    chars[ptr++] = num_str[j];
                }
                group_length = 1;
            }
            cur = c;
        }
        // write last one
        chars[ptr++] = cur;
        string num_str = "";
        if (group_length > 1)
        {
            while (group_length)
            {
                num_str += group_length % 10 + '0';
                group_length /= 10;
            }
        }
        for (int j = num_str.length() - 1; j >= 0; j--)
        {
            chars[ptr++] = num_str[j];
        }
        return ptr;
    }
};
// @lc code=end
