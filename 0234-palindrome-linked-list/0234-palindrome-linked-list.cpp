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
    bool isPalindrome(ListNode* head) {

        ListNode *curr_1 = head;
        ListNode *curr_2 = head;
        while (curr_2 && curr_2->next)
        {
            curr_1 = curr_1->next;
            curr_2 = curr_2->next->next;
        }

        //ListNode dummy(33, curr_1);
        ListNode* prev = nullptr;
        //ListNode* curr = head;
        while (curr_1)
        {
            ListNode* temp = curr_1->next;
            curr_1->next = prev;
            prev = curr_1;
            curr_1 = temp;
        }
        
        ListNode* p1 = prev;
        ListNode* p2 = head;

        while (p1 && p2)
        {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};