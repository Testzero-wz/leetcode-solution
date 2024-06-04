/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int total = 0;
        nums.emplace_back(1);
        int length = nums.size();
        queue<int> q;
        int p = 0;
        int start = 0;
        while (p < length)
        {
            if (nums[p] & 1 == 1)
            {
                if (q.size() < k)
                    q.push(p);
                else
                {
                    total += (q.front() - start + 1) * (p - q.back());
                    start = q.front() + 1;
                    q.pop();
                    q.push(p);
                }
            }
            p++;
        }
        return total;
    }
};
// @lc code=end
