# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        enum = 1
        l1_d = 0
        l2_d = 0
        while l1 is not None:
            l1_d += enum * l1.val
            enum *= 10
            l1 = l1.next
        enum = 1
        while l2 is not None:
            l2_d += enum * l2.val
            enum *= 10
            l2 = l2.next
        l = l1_d + l2_d
        prev = None
        for s in str(l):
            node = ListNode(int(s))
            node.next = prev
            prev = node 
        return node