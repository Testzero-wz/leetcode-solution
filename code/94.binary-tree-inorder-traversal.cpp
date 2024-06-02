/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> res;
        if (!root)
        {
            return res;
        }
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty())
        {
            TreeNode *top = stack.back();
            stack.pop_back();
            if (top)
            {
                // first time meet this node
                // tag it and push it's child
                if (top->right)
                    stack.push_back(top->right);
                stack.push_back(top);
                stack.push_back(nullptr);
                if (top->left)
                    stack.push_back(top->left);
            }
            else
            {
                res.push_back(stack.back()->val);
                stack.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
