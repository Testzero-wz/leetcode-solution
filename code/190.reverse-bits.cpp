/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1 == 1)
                res |= 1;
            n >>= 1;
            if (i != 31)
                res <<= 1;
        }
        return res;
    }
};
// @lc code=end
