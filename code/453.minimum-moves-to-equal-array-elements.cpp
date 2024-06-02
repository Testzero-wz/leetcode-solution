/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int min_val = nums[0];
        int moves = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (min_val < num)
            {
                moves += num - min_val;
            }
            else
            {
                moves += i * (min_val - num);
                min_val = num;
            }
        }
        return moves;
    }
};
// @lc code=end
