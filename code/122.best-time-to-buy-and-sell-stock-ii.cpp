/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int total_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int p = prices[i] - prices[i - 1];
            total_profit += p > 0 ? p : 0;
        }
        return total_profit;
    }
};
// @lc code=end
