class Solution:
    def findTarget(self, root, k: int) -> bool:
        #nums用來存遇到過的數
        nums=set()
        #從root開始編列,用來存放數字
        s=[root]
        #當s不為空,表示還有節點沒考慮到
        #就要繼續
        while s:
            #把s裡的最靠前之數字pop到nums中
            cur=s.pop()
            #如果k(要找的數字和)減掉cur後那個數字
            #能在nums中找到
            #那就成功證明k為兩個節點和
            if k-cur.val in nums:
                return True
            #如果沒找到
            #就把cur的值加進nums中
            nums.add(cur.val)
            #如果目前節點的左子點不為空
            #則append(存)進s中
            #右節點也一樣
            if cur.left:
                s.append(cur.left)
            if cur.right:
                s.append(cur.right)
        #如果一直進行迴圈,都沒找到可相加的節點的話
        #返回false
        #表示沒辦法為兩節點和
        return False
            