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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* merge_list = &dummy;
        ListNode* head = &dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                merge_list->next = list1;
                list1 = list1->next;
            }
            else
            {
                merge_list->next = list2;
                list2 = list2->next;
            }
            merge_list = merge_list->next;
        }
        if (list1) merge_list->next = list1;
        else    merge_list->next = list2;
        return head->next;
    }
};