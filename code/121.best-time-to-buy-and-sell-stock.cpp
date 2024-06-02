/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int cur_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int p = prices[i] - prices[i - 1];
            cur_profit += p;
            max_profit = max(cur_profit, max_profit);
            if (cur_profit < 0)
                cur_profit = 0;
        }
        return max_profit;
    }
};
// @lc code=end
