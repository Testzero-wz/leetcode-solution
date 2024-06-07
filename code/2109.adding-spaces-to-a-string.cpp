/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */

#include <string>
#include <vector>
#include <sstream>
using namespace std;
// @lc code=start
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        if (spaces.size() == 0)
            return s;
        string ss(s.length() + spaces.size(), ' ');
        int p = 0;
        int sp = spaces[p];
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == sp)
            {
                end++;
                sp = ++p < spaces.size() ? spaces[p] : -1;
            }
            ss[end++] = s[i];
        }
        return ss;
    }
};
// @lc code=end
