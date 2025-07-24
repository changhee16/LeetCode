# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        
        mid = self.findMid(head)
        left = head
        right = mid.next
        mid.next = None

        left = self.sortList(left)
        right = self.sortList(right)
        return self.mergeList(left, right)

    def findMid(self, head):
        low, high = head, head.next
        while high and high.next:
            low = low.next
            high = high.next.next
        return low
    def mergeList(self, left, right):
        dummy = tail = ListNode()

        while left and right:
            if left.val > right.val:
                #print("left : ", left.val, "right : ", right.val)
                tail.next = right
                right = right.next
            else:
                #print("!!left : ", left.val, "right : ", right.val)
                tail.next = left
                left = left.next
            tail = tail.next
        while left:
            tail.next = left
            left = left.next
            tail = tail.next
        while right:
            tail.next = right
            right = right.next
            tail = tail.next
        return dummy.next
