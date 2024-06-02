/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
using namespace std;
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        flat(root);
    }

    void flat(TreeNode *node)
    {
        if (node == nullptr)
            return;
        TreeNode *l = node->left;
        TreeNode *r = node->right;
        if (l == nullptr && r == nullptr)
            return;
        node->left = nullptr;
        flat(l);
        node->right = l;

        while (node->right != nullptr)
            node = node->right;
        node->right = r;
        
        flat(r);
    }
};
// @lc code=end
