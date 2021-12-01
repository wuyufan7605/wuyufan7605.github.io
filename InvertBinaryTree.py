 #定義節點的類別
 class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
#定義一個函式來左右交換
def DoInvertTree(root):
    #設置一個條件,避免讓函式一直跑不停
    if root==None:
        return None
    #左右節點交換
    #此處為python3特有的寫法,其他語言不能這樣寫
    root.left,root.right=root.right,root.left
    #root做完,換root的左右節點交換
    DoInvertTree(root.left)
    DoInvertTree(root.right)
    return root

class Solution:
    def invertTree(self, root) :
        return  DoInvertTree(root)