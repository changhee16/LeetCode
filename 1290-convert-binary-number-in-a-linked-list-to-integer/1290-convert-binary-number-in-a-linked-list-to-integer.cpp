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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head)
        {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};
/*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int res = 0;
        int two = 1;
        while (curr)
        {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        while (prev)
        {
            if (prev->val == 1) res += two;
            two *= 2;
            prev = prev->next;
        }
        return res;
    }
};
*/