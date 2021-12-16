# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root) -> int:
        #定義dfs函式
        def dfs(root):
            #如果沒有節點,就回傳0
            if not root:
                return 0
            #左右各自遞迴,繼續dfs
            left,right=dfs(root.left),dfs(root.right)
            #用res[0]把每次最大的乘機存起來
            #每次都用上次最大乘積,和左子點切割之乘積,右子點切割之乘積 做比較
            #取三者最大
            res[0]=max(res[0],left*(s[0]-left),right*(s[0]-right))
            #每次回傳到這節點,之加總總和
            return left+right+root.val
        #
        s=0
        #定義一個list叫q,裡面先放root
        q=[root]
        #當q裡面有東西就一直進入迴圈
        while q:
            #把q裡面的數字移除(pop出來)
            #python會pop出最後一個值
            #這邊只是要算總和
            #pop的順序沒差
            cur=q.pop()
            #每次把pop出的數字加進去s
            s+=cur.val
            #如果左子節點存在
            #放進q中
            if cur.left:
                q.append(cur.left)
            #如果右子節點存在
            #放進q中    
            if cur.right:
                q.append(cur.right)
        #s為所有節點總和
        #創一個叫s的列表
        #把總和的值放進s列表中
        s=[s]
        res=[0]
        #做dfs一個個追蹤
        dfs(root)
        #因題目規定
        #回傳值為除以(10**9+7)的餘數
        return res[0]%(10**9+7)