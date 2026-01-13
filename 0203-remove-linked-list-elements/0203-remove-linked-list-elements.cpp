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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head); 
        //dummy 노드 추가 : head 앞 노드를 만들면서 head가 삭제되는 분기를 만들지 않아도 처리가 가능하도록 함 
        if (!head) return head;

        ListNode *prev = &dummy;
        ListNode *curr = head;
        
        while (curr){
            if (curr->val == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }

        }
        return dummy.next;
    }
};