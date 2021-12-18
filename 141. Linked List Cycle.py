# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head):
        #設兩個指針,依題目要求
        #一個為長指針,一次走兩步,叫pl
        #一個為短指針,一次走一步,叫ps
        #兩個都指向串列頭
        ps=pl=head
        #都長指針現在指向的不是空,下一個節點也不為空
        #則長短指針都可以走下一步
        while pl and pl.next:
            pl=pl.next.next
            ps=ps.next
            #如果兩個指針相同,回傳True,否則False
            if pl==ps:
                return True
        return False