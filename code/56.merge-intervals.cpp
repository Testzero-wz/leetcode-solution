/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
bool f(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), f);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last_intervals = res.back();
            vector<int> &cur_intervals = intervals[i];
            if (cur_intervals[0] <= last_intervals[1])
                // merge
                last_intervals[1] = max(cur_intervals[1], last_intervals[1]);
            else
                // push
                res.push_back(cur_intervals);
        }
        return res;
    }
};
// @lc code=end
