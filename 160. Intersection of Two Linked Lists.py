# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA, headB) :
        #pa為一個指向A list頭的指針
        #pb為一個指向B list頭的指針
        pa=headA
        pb=headB
        while pa is not  pb:
            pa=headB if pa is None else pa.next
            pb=headA if pb is None else pb.next
        return pa
#解題思路:
#pa不斷往下一個節點移動,同時,pb也不斷往下一個節點移動
#因為A B list長度不相同
# 所以A:走a+c+b
#     B:走b+c+a後才相交 
#如果他們到了相同的點,就回傳:這個相交的點
#如果尚未相交就持續做迴圈
#就算兩個list沒有相交的點
#把點都run過一遍後,也會在null處相交
#本來應該要設定:
#若兩個list有一個為空
#就return None
#但是題目規定兩個list都至少有一個節點,所以略過