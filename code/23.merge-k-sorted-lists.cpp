/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
struct Compare
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        priority_queue<ListNode *, vector<ListNode *>, Compare> q;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != nullptr)
                q.push(lists[i]);

        ListNode *top;
        while (!q.empty())
        {
            top = q.top();
            q.pop();
            cur->next = top;
            cur = top;
            if (top->next != nullptr)
                q.push(top->next);
        }
        return head->next;
    }
};
// @lc code=end
