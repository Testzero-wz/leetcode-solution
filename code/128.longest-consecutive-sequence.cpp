/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        unordered_set<int> s;
        for (auto n : nums)
            s.insert(n);
        int max_cnt = 0;
        int start = *s.begin();
        int end = *s.begin();
        s.erase(s.begin());
        while (!s.empty())
        {
            auto fs = s.find(start - 1);
            if (fs != s.end())
            {
                start--;
                s.erase(fs);
                continue;
            }
            auto fe = s.find(end + 1);
            if (fe != s.end())
            {
                end++;
                s.erase(fe);
                continue;
            }
            // can't find either
            max_cnt = max(max_cnt, end - start + 1);
            start = *s.begin();
            end = *s.begin();
            s.erase(s.begin());
        }
        max_cnt = max(max_cnt, end - start + 1);
        return max_cnt;
    }
};
// @lc code=end
