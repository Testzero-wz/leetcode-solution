/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int cur_sum = 0;
        vector<int> stack;
        vector<vector<int>> res;
        if (root != nullptr)
            dfs(root, cur_sum, targetSum, stack, res);
        return res;
    }

    void dfs(TreeNode *node, int &cur_sum, int targetSum, vector<int> &stack, vector<vector<int>> &res)
    {
        cur_sum += node->val;
        stack.push_back(node->val);
        if (cur_sum == targetSum && node->left == nullptr && node->right == nullptr)
            res.push_back(stack);
        if (node->left != nullptr)
            dfs(node->left, cur_sum, targetSum, stack, res);
        if (node->right != nullptr)
            dfs(node->right, cur_sum, targetSum, stack, res);
        cur_sum -= node->val;
        stack.pop_back();
    }
};
// @lc code=end
