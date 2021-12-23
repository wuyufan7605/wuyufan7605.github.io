# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self,h1,h2):
        #設一個叫dummy的點,tail指針指向他
        #ListNode()為leetcode上定義好的類別
        dummy=tail=ListNode()
        #h1指向左子串(subset)的頭
        #h2指向右字串(subset)的頭
        while h1 and h2:
            #如果左邊的頭比較小
            #tail指向左邊的頭,tail.next也是
            #h1指向左邊的頭的下一個數
            if h1.val<h2.val:
                tail.next=h1
                tail=h1
                h1=h1.next
            #如果右邊的頭(數字)較小
            #重複剛剛左邊做的
            else:
                tail.next=h2
                tail=h2
                h2=h2.next
        #如果其中一邊跑完,另一邊還沒跑完
        #比如右邊跑完,左邊還沒
        #就不會再進入上面的迴圈
        #因為右邊為null
        #這時,tail.next繼續指向左邊還沒完的數字
        tail.next=h1 or h2
        #最後回傳合併好的排列
        return dummy.next
       
        
    def sortList(self,head: ListNode) -> ListNode:
        
        #如果這個鏈表為空,或只有一個節點
        #就直接return head
        if not head or not head.next:
            return head
        #以pre及快慢指針來進行分開(divide)
        pre, slow, fast = None, head, head
        #用while進行分開
        #比如說: 1,3,5,2,4,6
        #一開始:
        #pre=1,slow=3,fast=5
        #後來:
        # pre=3,slow=5,fast=4
        # 再來:
        # pre=5,slow=2,fast=null
        # 所以,以head為首 1,3,5一邊 
        #以slow為首 2,4,6一邊
        while fast and fast.next:
            pre,slow,fast=slow, slow.next, fast.next.next
        pre.next=None
        #再合併兩個鏈表
        return self.merge(self.sortList(head),self.sortList(slow))