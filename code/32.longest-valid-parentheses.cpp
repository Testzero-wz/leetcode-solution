/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> stack;
        int cnt = 0;
        int max_cnt = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                if (cnt != 0)
                {
                    stack.push_back(cnt);
                    cnt = 0;
                }
                stack.push_back(-1);
            }
            else if (c == ')')
            {
                if (stack.empty())
                {
                    max_cnt = max(cnt, max_cnt);
                    cnt = 0;
                }
                else
                {
                    // pop back '('
                    stack.pop_back();
                    cnt += 2;
                    // add
                    if (!stack.empty() && stack.back() != -1)
                    {
                        cnt += stack.back();
                        stack.pop_back();
                    }
                    max_cnt = max(cnt, max_cnt);
                }
            }
        }
        return max_cnt;
    }
};
// @lc code=end
