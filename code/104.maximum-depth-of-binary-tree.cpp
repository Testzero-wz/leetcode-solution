/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        int d = 0;
        int md = 0;
        if (root != nullptr)
            f(root, d, md);
        return md;
    }
    void f(TreeNode *node, int &depth, int &max_depth)
    {
        depth++;
        if (node->left != nullptr)
            f(node->left, depth, max_depth);
        if (node->right != nullptr)
            f(node->right, depth, max_depth);
        if (node->left == nullptr && node->right == nullptr)
            max_depth = max(max_depth, depth);
        depth--;
    }
};
// @lc code=end
