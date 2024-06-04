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
        stringstream ss;
        int p = 0;
        int cur_space_idx = spaces[p];
        for (int i = 0; i < s.size(); i++)
        {
            if (i == cur_space_idx)
            {
                ss << ' ';
                cur_space_idx = ++p < spaces.size() ? spaces[p] : -1;
            }
            ss << s[i];
        }
        if (spaces.back() == s.size())
            ss << " ";
        return ss.str();
    }
};
// @lc code=end
