/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    typedef struct symbol
    {
        char c;
        int cnt;
    } symbol;
    bool isValid(string s)
    {
        vector<symbol *> symbols = vector<symbol *>();
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
            {
                if (!symbols.empty())
                {
                    symbol *top = symbols.back();
                    if (c == top->c)
                    {
                        top->cnt++;
                    }
                    else
                    {
                        symbols.push_back(new symbol{c, 1});
                    }
                }
                else
                {
                    symbols.push_back(new symbol{c, 1});
                }
                break;
            }
            case ')':
            case ']':
            case '}':
            {
                if (symbols.empty())
                {
                    return false;
                }
                symbol *top = symbols.back();
                if (!is_match(top->c, c))
                {
                    return false;
                }
                top->cnt--;
                if (top->cnt == 0)
                {
                    symbols.pop_back();
                }
                break;
            }
            default:
                continue;
            }
        }
        return symbols.empty();
    }

    bool is_match(char l, char r)
    {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
};
// @lc code=end
