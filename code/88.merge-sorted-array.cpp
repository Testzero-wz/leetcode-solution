/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
int MAX = 1000000000 + 1;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        if (n == 0)
        {
            return;
        }
        // move element to nums1 bottom
        int tail = nums1.size() - 1;
        int last = m - 1;
        while (last >= 0)
        {
            nums1[tail] = nums1[last];
            nums1[last] = 0;
            tail--;
            last--;
        }
        int p1 = tail + 1;
        int p2 = 0;
        int p = 0;
        while (p1 < nums1.size() || p2 < nums2.size())
        {
            int n1 = p1 < nums1.size() ? nums1[p1] : MAX;
            int n2 = p2 < nums2.size() ? nums2[p2] : MAX;
            if (n1 < n2)
            {
                nums1[p] = n1;
                p1++;
            }
            else
            {
                nums1[p] = n2;
                p2++;
            }
            p++;
        }
    }
};
// @lc code=end
