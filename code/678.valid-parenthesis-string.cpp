/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkValidString(string str)
    {
        vector<int> l;
        vector<int> s;
        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c == '(')
            {
                l.push_back(i);
            }
            else if (c == '*')
            {
                s.push_back(i);
            }
            else
            {
                // ')'
                if (l.empty() && s.empty())
                    return false;
                if (!l.empty())
                {
                    l.pop_back();
                    continue;
                }
                if (!s.empty())
                {
                    s.pop_back();
                    continue;
                }
            }
        }
        while (!l.empty())
        {
            if (s.empty())
                return false;
            if (l.back() > s.back())
                return false;
            l.pop_back();
            s.pop_back();
        }
        return true;
    }
};
// @lc code=end
