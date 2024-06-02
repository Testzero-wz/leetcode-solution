/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *root = new ListNode(-1, head);
        ListNode *prev = root;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return root->next;
    }
};
// @lc code=end
