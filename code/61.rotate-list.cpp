/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *tail = head;
        int list_size = 1;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            list_size++;
        }
        if (tail == head)
        {
            return head;
        }
        k = k % list_size;
        k = list_size - k;
        tail->next = head;
        while (k)
        {
            head = head->next;
            tail = tail->next;
            k--;
        }
        tail->next = nullptr;
        return head;
    }
};
// @lc code=end
