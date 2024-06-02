/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *ptr = head;
        int num = head->val;
        while (ptr->next != nullptr)
        {
            if (ptr->next->val == num)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
                num = ptr->val;
            }
        }
        return head;
    }
};
// @lc code=end
