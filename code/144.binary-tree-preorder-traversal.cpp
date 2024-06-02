/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (!stack.empty())
        {
            TreeNode *top = stack.back();
            stack.pop_back();
            if (top)
            {
                // first time meet this node
                // tag it
                if (top->right)
                    stack.push_back(top->right);
                if (top->left)
                    stack.push_back(top->left);
                stack.push_back(top);
                stack.push_back(nullptr);
            }
            else
            {
                // visit
                top = stack.back();
                stack.pop_back();
                res.push_back(top->val);
            }
        }
        return res;
    }
};
// @lc code=end
