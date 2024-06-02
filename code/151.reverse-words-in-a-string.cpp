/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */
#include <string>
#include <sstream>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss;
        int start;
        int end = s.length() - 1;
        bool is_first = true;
        while (1)
        {
            while (end >= 0 && s[end] == ' ')
                end--;
            if (end < 0)
                break;
            start = end;
            while (start >= 0 && s[start] != ' ')
                start--;
            if (!is_first)
                ss << " ";
            if (is_first)
                is_first = false;
            for (int i = start + 1; i <= end; i++)
                ss << s[i];
            if (start == -1)
                break;
            end = start;
        }
        return ss.str();
    }
};
// @lc code=end
