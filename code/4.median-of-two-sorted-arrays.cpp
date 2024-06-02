/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int length_sum = s1 + s2;
        int stop = length_sum / 2;
        int MIN = -1000000 - 1;
        int MAX = 1000000 + 1;
        bool even = length_sum % 2 == 0;
        if (even)
        {
            stop -= 1;
        }
        int i = 0;
        int j = 0;
        int m1 = 0;
        int m2 = 0;
        while (1)
        {
            if (i >= s1 && j >= s2)
            {
                break;
            }
            int n1 = i < s1 ? nums1[i] : MAX;
            int n2 = j < s2 ? nums2[j] : MAX;
            if (i + j >= stop)
            {
                if (i + j == stop)
                {
                    m1 = min(n1, n2);
                }
                else
                {
                    m2 = min(n1, n2);
                    break;
                }
                if (!even)
                {
                    break;
                }
            }
            if (n1 <= n2)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        if (even)
        {
            return ((float)m1 + m2) / 2;
        }
        return (float)m1;
    }
};
// @lc code=end
