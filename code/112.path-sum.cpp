/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool found = false;
        dfs(root, sum, targetSum, found);
        return found;
    }

    void dfs(TreeNode *node, int &sum, int targeSum, bool &found)
    {
        if (node == nullptr)
            return;
        if (found)
            return;
        // visit
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (targeSum == sum)
                found = true;
            sum -= node->val;
            return;
        }

        dfs(node->left, sum, targeSum, found);
        dfs(node->right, sum, targeSum, found);

        sum -= node->val;
    }
};
// @lc code=end
