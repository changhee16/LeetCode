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
    ListNode* middleNode(ListNode* head) {
        //ListNode dummy(300, head);
        ListNode *curr_1 = head;
        ListNode *curr_2 = head;
        while (curr_2 && curr_2->next)
        {
            curr_1 = curr_1->next;
            curr_2 = curr_2->next->next;
        }
        return curr_1;
    }
};