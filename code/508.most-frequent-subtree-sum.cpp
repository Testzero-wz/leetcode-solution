/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    unordered_map<int, int> sums;
    int max_count = 0;
    int post_travel(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int sum = node->val;
        sum += post_travel(node->left);
        sum += post_travel(node->right);

        if (sums.find(sum) != sums.end())
            sums[sum]++;
        else
            sums[sum] = 1;
        max_count = max(sums[sum], max_count);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        vector<int> res;
        post_travel(root);
        for (auto it : sums)
        {
            if (it.second == max_count)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
// @lc code=end
