/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    bool is_num_char(char c)
    {
        return c <= '9' && c >= '0';
    }
    int read_num(string &s, int ops)
    {
        int stop = min<int>(ops + 3, s.length());
        int res = 0;
        int num = 0;
        bool leading_zero = false;
        for (; ops < stop; ops++)
        {
            char c = s[ops];
            if (!is_num_char(c))
            {
                break;
            }
            if (leading_zero)
            {
                return -1;
            }
            if (c == '0' && res == 0)
            {
                leading_zero = true;
            }
            res += 1;
            num = num * 10 + (c - '0');
        }
        if (num <= 255 && num >= 0)
        {
            return res;
        }
        return -1;
    }
    bool is_valid_ipv4(string &s)
    {
        int ops = 0;
        for (int i = 0; i < 4; i++)
        {
            int n = read_num(s, ops);
            if (n <= 0)
            {
                return false;
            }
            ops += n;
            if (i == 3)
            {
                break;
            }
            if (ops >= s.length() || s[ops] != '.')
            {
                return false;
            }
            ops += 1;
        }
        return ops == s.length();
    }

    bool is_hex_char(char c)
    {
        return (c >= 'a' && c <= 'f') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
    }

    int read_hex_num(string &s, int ops)
    {
        int stop = min<int>(ops + 4, s.length());
        int res = 0;
        for (; ops < stop; ops++)
        {
            char c = s[ops];
            if (!is_hex_char(c))
            {
                break;
            }
            res += 1;
        }
        return res;
    }

    bool is_valid_ipv6(string &s)
    {
        int ops = 0;
        for (int i = 0; i < 8; i++)
        {
            int n = read_hex_num(s, ops);
            if (n <= 0)
            {
                return false;
            }
            ops += n;
            if (i == 7)
            {
                break;
            }
            if (ops >= s.length() || s[ops] != ':')
            {
                return false;
            }
            ops += 1;
        }
        return ops == s.length();
    }
    string validIPAddress(string queryIP)
    {
        if (is_valid_ipv4(queryIP))
        {
            return "IPv4";
        }
        else if (is_valid_ipv6(queryIP))
        {
            return "IPv6";
        }
        return "Neither";
    }
};
// @lc code=end
