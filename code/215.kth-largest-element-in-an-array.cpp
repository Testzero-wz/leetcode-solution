// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, std::greater<int>> q;

        for (auto num : nums)
        {
            if (q.empty() || q.size() < k){
                q.push(num);
                continue;
            }
            if (num < q.top())
                continue;
            q.pop();
            q.push(num);
        }
        return q.top();
    }
};
// @lc code=end
