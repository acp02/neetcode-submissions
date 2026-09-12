# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        elif list2 is None:
            return list1
        values = []
        curr1 = list1
        while curr1:
            values.append(curr1.val)
            curr1 = curr1.next

        curr2 = list2
        while curr2:
            values.append(curr2.val)
            curr2 = curr2.next

        values.sort()

        newhead = ListNode(values[0]) 
        curr = newhead
        for i in range(1, len(values)):
            curr.next = ListNode(values[i])
            curr = curr.next

        return newhead
        
