/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        // inorder traval
        vector<TreeNode *> stack;
        stack.push_back(root);
        TreeNode *cur;
        bool first = true;
        int val;
        while (!stack.empty())
        {
            cur = stack.back();
            stack.pop_back();
            if (cur != nullptr)
            {
                if (cur->right != nullptr)
                    stack.push_back(cur->right);
                stack.push_back(cur);
                stack.push_back(nullptr);
                if (cur->left != nullptr)
                    stack.push_back(cur->left);
            }
            else
            {
                cur = stack.back();
                stack.pop_back();
                // visit
                if (first)
                    first = false;
                else if (!(val < cur->val))
                    return false;
                val = cur->val;
            }
        }
        return true;
    }
};
// @lc code=end
