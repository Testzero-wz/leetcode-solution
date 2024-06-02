/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Codec
{
public:
    // preorder
    string bfs(TreeNode *node)
    {
        string tmp;
        if (node == nullptr)
            return "N ";
        tmp += to_string(node->val) + " ";
        tmp += bfs(node->left);
        tmp += bfs(node->right);
        return tmp;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        return bfs(root);
    }

    TreeNode *rbfs(stringstream &ss)
    {
        string s;
        ss >> s;
        if (s == "N")
            return nullptr;
        int val = stoi(s);
        TreeNode *n = new TreeNode(val);
        n->left = rbfs(ss);
        n->right = rbfs(ss);
        return n;
    };

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data)
    {
        stringstream ss;
        ss << data;
        return rbfs(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
