/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */
#include <vector>
using namespace std;
// @lc code=start

class Solution
{
public:
    int MASK_1 = 0x80;
    int MASK_2 = 0xE0;
    int MASK_3 = 0xF0;
    int MASK_4 = 0xF8;
    int SIG_1 = 0x00;
    int SIG_2 = 0xC0;
    int SIG_3 = 0xE0;
    int SIG_4 = 0xF0;

    int MASK_REMAIN = 0xC0;
    int VALUE_REMAIN = 0x80;
    int get_sig(int b1)
    {
        if ((b1 & MASK_1) == SIG_1)
            return 1;
        if ((b1 & MASK_2) == SIG_2)
            return 2;
        if ((b1 & MASK_3) == SIG_3)
            return 3;
        if ((b1 & MASK_4) == SIG_4)
            return 4;
        return -1;
    }
    int get_int(vector<int> &data, int idx)
    {
        if (idx >= 0 && idx < data.size())
            return data[idx];
        return -1;
    }
    bool validUtf8(vector<int> &data)
    {
        int idx = 0;
        while (1)
        {
            int b1 = get_int(data, idx);
            if (b1 == -1)
            {
                break;
            }
            int sig = get_sig(b1);
            if (sig == -1)
            {
                return false;
            }
            if (idx + sig > data.size())
            {
                return false;
            }
            // skip cur char;
            idx++;

            for (int i = 1; i < sig; i++)
            {
                if ((MASK_REMAIN & data[idx]) != VALUE_REMAIN)
                    return false;
                idx++;
            }
        }
        return true;
    }
};
// @lc code=end
