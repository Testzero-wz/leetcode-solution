/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        vector<char> buf;
        gen(n, 0, buf, res);
        return res;
    }

    void gen(int rcnt, int ecnt, vector<char> &buf, vector<string> &res)
    {
        if (rcnt == 0 && ecnt == 0)
        {
            res.push_back(string(buf.begin(), buf.end()));
            return;
        }
        // eject first
        if (rcnt > 0)
        {
            buf.push_back('(');
            gen(rcnt - 1, ecnt + 1, buf, res);
            buf.pop_back();
        }
        // close
        if (ecnt > 0)
        {
            buf.push_back(')');
            gen(rcnt, ecnt - 1, buf, res);
            buf.pop_back();
        }
        return;
    }
};
// @lc code=end
