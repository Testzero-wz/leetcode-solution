/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        vector<Node *> stack;
        stack.push_back(root);
        while (!stack.empty())
        {
            Node *top = stack.back();
            stack.pop_back();
            if (top)
            {
                // first time meet this node
                // tag it
                for (auto rit = top->children.rbegin(); rit != top->children.rend(); rit++)
                {
                    stack.push_back(*rit);
                }
                stack.push_back(top);
                stack.push_back(nullptr);
            }
            else
            {
                top = stack.back();
                stack.pop_back();
                res.push_back(top->val);
            }
        }
        return res;
    }
};
// @lc code=end
