/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    char read_char(string &s, int sp)
    {
        if (sp >= 0 && sp < s.length())
        {
            return s[sp];
        }
        return -1;
    }
    bool is_num_char(char c)
    {
        return c >= '0' && c <= '9';
    }
    long long read_num(string &s, int &sp)
    {
        long long num = 0;
        char c;
        while (is_num_char(c = read_char(s, sp)))
        {
            num = num * 10 + c - '0';
            sp++;
        }
        return num;
    }
    int calculate(string s)
    {
        int sp = 0;
        vector<long long> nums;
        vector<char> ops;
        bool num_cnt = 0;
        while (1)
        {
            char c = read_char(s, sp);
            sp++;
            if (c == -1)
            {
                break;
            }
            if (c == ' ')
                continue;
            if (is_num_char(c))
            {
                sp--;
                int num = read_num(s, sp);
                nums.push_back(num);
                continue;
            }
            // ops
            push_op(c, ops, nums);
        }
        // end
        push_op('?', ops, nums);
        return nums.back();
    }

    int get_op_pri(char c)
    {
        if (c == '+' || c == '-')
        {
            return 1;
        }
        else if (c == '*' || c == '/')
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    void push_op(char op, vector<char> &ops, vector<long long> &nums)
    {
        int cur_op_pri = get_op_pri(op);
        while (1)
        {
            if (ops.empty())
            {
                break;
            }
            char c = ops.back();
            int top_op_pri = get_op_pri(c);
            if (cur_op_pri > top_op_pri)
            {
                break;
            }
            ops.pop_back();
            switch (c)
            {
            case '+':
            {
                nums.push_back(pop(nums) + pop(nums));
                break;
            }
            case '-':
            {
                nums.push_back(-(pop(nums) - pop(nums)));
                break;
            }
            case '*':
            {
                nums.push_back(pop(nums) * pop(nums));
                break;
            }
            case '/':
            {
                long long n1 = pop(nums);
                long long n2 = pop(nums);
                nums.push_back(n2 / n1);
                break;
            }
            default:
            {
                exit(-1);
            }
            }
        }
        ops.push_back(op);
        return;
    }

    template <typename T>
    T pop(vector<T> &v)
    {
        T top = v.back();
        v.pop_back();
        return top;
    }
};
// @lc code=end
