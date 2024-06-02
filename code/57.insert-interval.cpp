/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int idx = 0;
        int has_insert = false;
        while (idx < intervals.size() || !has_insert)
        {
            vector<int> cur;
            if (idx < intervals.size() && (has_insert || (!has_insert && intervals[idx][0] < newInterval[0])))
            {
                cur = intervals[idx];
                idx++;
            }
            else
            {
                cur = newInterval;
                has_insert = true;
            }
            if (res.empty())
            {
                res.push_back(cur);
            }
            else
            {
                vector<int> &last = res.back();
                if (cur[0] <= last[1])
                {
                    // merge
                    last[1] = max(last[1], cur[1]);
                }
                else
                {
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
// @lc code=end
