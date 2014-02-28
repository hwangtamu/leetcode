# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        n1 = []
        n2 = []
        while True:
            if l1.next != None:
                n1.append(l1.val)
                l1 = l1.next
            if l1.next == None:
                n1.append(l1.val)
                break
        while True:
            if l2.next != None:
                n2.append(l2.val)
                l2 = l2.next
            if l2.next == None:
                n2.append(l2.val)
                break
        num1 = 0
        num2 = 0
        if len(n1)>0:
            for i in range(len(n1)):
                num1 += n1[i]*pow(10,i)
        if len(n2)>0:
            for i in range(len(n2)):
                num2 += n2[i]*pow(10,i)
        s = str(num1 + num2)
        ans = []
        for i in range(len(s)):
            node = ListNode(s[-i-1])
            #node.next = None
            ans.append(node)
        if len(ans)>1:
            for i in range(len(ans)-1):
                ans[i].next = ans[i+1]
        return ans[0]
