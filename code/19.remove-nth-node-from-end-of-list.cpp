/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *root = new ListNode(-1, head);
        ListNode *n1 = root;
        ListNode *n2 = root;
        while (1)
        {
            if (n1->next == nullptr)
            {
                n2->next = n2->next->next;
                break;
            }
            n1 = n1->next;
            if (n <= 0)
            {
                n2 = n2->next;
            }
            n--;
        }
        return root->next;
    }
};
// @lc code=end
