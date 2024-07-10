import collections
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        queue = collections.deque()
        if not head:
            return True
        while head is not None:
            queue.append(head.val)
            head = head.next
        while len(queue) > 1:
            if queue.popleft() != queue.pop():
                return False
        return True