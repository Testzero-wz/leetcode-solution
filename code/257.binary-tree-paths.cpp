/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> stack;
        vector<string> res;
        if(root == nullptr)
            return res;
        dfs(root, stack, res);
        return res;
    }

    void dfs(TreeNode *node, vector<int> &stack, vector<string> &res)
    {
        stack.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            // leaf
            gen_path(stack, res);
        }
        else
        {
            if (node->left != nullptr)
                dfs(node->left, stack, res);
            if (node->right != nullptr)
                dfs(node->right, stack, res);
        }
        stack.pop_back();
    }

    void gen_path(vector<int> &stack, vector<string> &res)
    {
        stringstream ss;
        for (int i = 0; i < stack.size(); i++)
        {
            ss << stack[i];
            if (i != stack.size() - 1)
                ss << "->";
        }
        res.push_back(ss.str());
    }
};
// @lc code=end
