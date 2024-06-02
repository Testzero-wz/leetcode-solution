/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

    ListNode *find_mid(ListNode *head)
    {
        // slow & fast pointer
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *mergeSort(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        ListNode *mid = find_mid(node);
        ListNode *left = node;
        ListNode *right = mid->next;
        mid->next = nullptr;
        return merge(mergeSort(left), mergeSort(right));
    }
    ListNode *merge(ListNode *list_a, ListNode *list_b)
    {
        ListNode *merged = new ListNode(0);
        ListNode *ptr = merged;
        while (list_a != nullptr && list_b != nullptr)
        {
            if (list_a->val < list_b->val)
            {
                ptr->next = list_a;
                list_a = list_a->next;
            }
            else
            {
                ptr->next = list_b;
                list_b = list_b->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list_a != nullptr ? list_a : list_b;
        return merged->next;
    }
};
// @lc code=end
