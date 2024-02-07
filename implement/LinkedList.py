class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next 

class LinkedList:
    def __init__(self) -> None:
        self.head = None 
    def append(self, val):
        if not self.head:
            self.head = ListNode(val, None)
            return

        while self.head.next:
            self.head = self.head.next

        self.head.next = ListNode(val, None) 
    def getLinkedList(self):
        return self.head

if __name__ == "__main__":
    linked_list = LinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(2)
    linked_list.append(1)
    getted = linked_list.getLinkedList()
    print(getted)