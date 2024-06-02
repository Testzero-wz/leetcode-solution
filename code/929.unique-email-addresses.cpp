/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// @lc code=start
class Solution
{
public:
    string getEmailString(string &name)
    {
        stringstream ss;
        int at_idx = name.find("@");
        for (int i = 0; i < at_idx; i++)
        {
            char c = name[i];
            if (c >= 'a' && c <= 'z')
            {
                ss << c;
            }
            else if (c == '.')
            {
                continue;
            }
            else if (c == '+')
            {
                break;
            }
        }
        ss << name.substr(at_idx);
        return ss.str();
    }
    int numUniqueEmails(vector<string> &emails)
    {
        map<string, void *> m;
        for (auto s : emails)
            m[getEmailString(s)] = nullptr;
        return m.size();
    }
};
// @lc code=end
