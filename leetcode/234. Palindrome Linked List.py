from copy import deepcopy
class Solution:
    def __init__(self,):
        self.stack = []
    def isPalindrome(self, head) -> bool:
        while head.next is not None:
            self.stack.append(head.val)
            head = head.next
        else:
            self.stack.append(head.val)
        copied = deepcopy(self.stack)[::-1]
        if self.stack == copied:
            return True
        else:
            return False