/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 struct ListNode* createNode() {
    struct ListNode *node; //why pointer? malloc 할당을 받기 위해 
    node = (struct ListNode *)malloc(sizeof(struct ListNode));
    return node;
}

//조작이 원본에 반영이 되려면 pointer로 넘겨야 한다 
struct ListNode* mergeList(struct ListNode* left, struct ListNode* right){
    struct ListNode *dummy = createNode();
    struct ListNode *tail = dummy;
        while (left && right)
        {
            if (left->val > right->val)
            {
                tail->next = right;
                right = right->next;
            }
            else
            {
                tail->next = left;
                left = left->next;
            }
            tail = tail->next;
        }
        while (left)
        {
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        while (right)
        {
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }
        return dummy->next;
}
struct ListNode* findMid(struct ListNode* head) {
    struct ListNode* low = head;
    struct ListNode* high = head->next; //둘다 pointer로 선언해야 접근 가능하다고 한다. 
    while (high && high->next)
    {
        low = low->next;
        high = high->next->next;
    }
    return low;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* mid = findMid(head);
    struct ListNode* left = head;
    struct ListNode* right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);
    return mergeList(left, right);
}



