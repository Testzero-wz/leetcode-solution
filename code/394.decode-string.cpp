/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution
{
public:
    char read_char(string &s, int sp)
    {
        if (s.length() > sp)
        {
            return s[sp];
        }
        return -1;
    }

    string decodeString(string s)
    {
        return f(s, 0, s.length());
    }

    string f(string &s, int sp, int se)
    {
        int mul = 0;
        string tmp = "";
        stringstream ss = stringstream();
        while (1)
        {
            if (sp == se)
            {
                break;
            }
            char c = read_char(s, sp);
            if (c == -1)
            {
                break;
            }
            sp++;
            if (c >= 'a' && c <= 'z')
            {
                ss << c;
            }
            else if (c >= '0' && c <= '9')
            {
                int num = c - '0';
                while (1)
                {
                    char c = read_char(s, sp);
                    sp++;
                    if (!(c >= '0' && c <= '9'))
                    {
                        sp--;
                        break;
                    }
                    num = num * 10 + c - '0';
                }
                mul = num;
            }
            else if (c == '[')
            {
                int o_sp = sp;
                int l_cnt = 1;
                while (char c = read_char(s, sp))
                {
                    sp++;
                    if (c == '[')
                    {
                        l_cnt++;
                    }
                    else if (c == ']')
                    {
                        l_cnt--;
                    }
                    if (l_cnt == 0)
                    {
                        break;
                    }
                }
                tmp = f(s, o_sp, sp - 1);
                while (mul--)
                {
                    ss << tmp;
                }
            }
            else
            {
                exit(-1);
            }
        }
        return ss.str();
    }
};
// @lc code=end
