/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        map<string, int> m;
        vector<int> v;
        int id = 0;
        for (auto c : pattern)
        {
            string tmp_s = string(1, c);
            if (m.find(tmp_s) == m.end())
            {
                m[tmp_s] = id++;
            }
            v.push_back(m[tmp_s]);
        }
        id = 0;
        stringstream ss(s);
        string tmp_s;
        m.clear();
        int idx = 0;
        while (getline(ss, tmp_s, ' '))
        {
            if(idx >= v.size())
                return false;
            if (m.find(tmp_s) == m.end())
                m[tmp_s] = id++;
            if (m[tmp_s] != v[idx])
                return false;
            idx++;
        }
        return idx==v.size();
    }
};
// @lc code=end
