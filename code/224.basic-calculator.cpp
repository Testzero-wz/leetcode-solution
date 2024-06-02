/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    char read_char(string &s, int sp)
    {
        if (sp < s.length())
            return s[sp];
        return -1;
    }
    bool is_num_char(char c)
    {
        return c >= '0' && c <= '9';
    }
    long long read_num(string &s, int &sp)
    {
        char c;
        long long num = 0;
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
        vector<long long> nums = vector<long long>();
        vector<char> ops = vector<char>();
        bool rnum = false;
        int num_cnt = 0;
        while (1)
        {
            char c = read_char(s, sp);
            sp++;
            if (c == -1)
            {
                break;
            }
            if (c == ' ')
            {
                continue;
            }
            if (is_num_char(c))
            {
                sp--;
                long long num = read_num(s, sp);
                nums.push_back(num);
                if (rnum)
                {
                    // execute op
                    exec_top_op(ops, nums);
                }
                num_cnt++;
                rnum = false;
                continue;
            }

            switch (c)
            {
            case '(':
                num_cnt = 0;
                ops.push_back(c);
                break;
            case '+':
                rnum = true;
                ops.push_back(c);
                break;
            case '-':
                rnum = true;
                if (num_cnt == 0)
                    ops.push_back('n');
                else
                    ops.push_back(c);
                break;
            case ')':
                // pop out '('
                // and execute top op
                if (ops.back() != '(')
                {
                    exit(-1);
                }
                pop(ops);
                exec_top_op(ops, nums);
            }
        }
        return nums.back();
    }
    template <typename T>
    T pop(vector<T> &v)
    {
        T top = v.back();
        v.pop_back();
        return top;
    }

    void exec_top_op(vector<char>& ops, vector<long long>& nums)
    {
        if (ops.empty())
            return;

        if (ops.back() == '(')
            return;

        char op = pop(ops);
        switch (op)
        {
        case '+':
            nums.push_back(pop(nums) + pop(nums));
            break;
        case '-':
            nums.push_back(-(pop(nums) - pop(nums)));
            break;
        case 'n':
            nums.push_back(-pop(nums));
            break;
        default:
            // unexpected op
            exit(-1);
        }
        return;
    }
};
// @lc code=end
