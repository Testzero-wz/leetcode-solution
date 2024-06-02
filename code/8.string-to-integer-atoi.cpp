/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
// @lc code=start
class Solution
{
public:
    long long POS_MAX = 2147483647;
    long long NEG_MAX = POS_MAX + 1;
    long long ERR_NUM = POS_MAX + 1000;
    char get_char(string &s, int sp)
    {
        if (sp < s.length())
            return s[sp];
        return -1;
    }
    int get_sig(string &s, int sp)
    {
        char c = get_char(s, sp);
        if (c == -1)
        {
            return -1;
        }
        if (c == '+')
        {
            return 1;
        }
        if (c == '-')
        {
            return 2;
        }
        return 0;
    }
    int skip_ws(string &s, int sp)
    {
        int cnt = 0;
        while (1)
        {
            char c = get_char(s, sp);
            if (c == -1)
            {
                return -1;
            }
            sp++;
            if (c != ' ')
            {
                break;
            }
            cnt++;
        }
        return cnt;
    }
    char get_num_char(string &s, int sp)
    {
        char c = get_char(s, sp);
        if (c == -1)
        {
            return -1;
        }
        if (c >= '0' && c <= '9')
        {
            return c;
        }
        return -1;
    }
    long long get_num(string &s, int sp, bool neg_flag)
    {
        long long num = 0;
        while (1)
        {
            char c = get_num_char(s, sp);
            sp++;
            if (c == -1)
            {
                return num;
            }
            num = num * 10 + (c - '0');
            if ((neg_flag && num >= NEG_MAX) || (!neg_flag && num >= POS_MAX))
            {
                if (neg_flag)
                {
                    return NEG_MAX;
                }
                else
                {
                    return POS_MAX;
                }
            }
        }
    }
    int myAtoi(string s)
    {
        int sp = 0;
        int o = skip_ws(s, sp);
        if (o == -1)
        {
            return 0;
        }
        sp += o;
        o = get_sig(s, sp);
        if (o == -1)
        {
            return 0;
        }
        bool neg_flag = o == 2;
        if (o != 0)
            sp++;
        long long num = get_num(s, sp, neg_flag);
        if (num == ERR_NUM)
        {
            return 0;
        }
        if (neg_flag)
        {
            return -num;
        }
        return num;
    }
};
// @lc code=end
