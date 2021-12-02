# 定義二元樹節點的類別(leetcode已經訂好)
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#定義一個函式
#找出節點的 層數(level) 同一層中第幾個數字(由0開始)
def dfs(root,level,index,m):
    #設一個條件,避免一直跑個不停
    if root==None:
        return
    #因為m[0]->key error
    #所以設定原本就有的話,就把index新增進去
    if level in m:
        m[level].append(index)
    #若沒有的話([m[0]),就新生一個列表,裡面有一個index
    else:
        m[level]=[index]
    #列印是測試用
    #print(root.val,":",level,index,m)
    #再往左子點做
    #再往右子點做
    dfs(root.left,level+1,index*2,m)
    dfs(root.right,level+1,index*2+1,m)

class Solution:
    def widthOfBinaryTree(self, root):
        #m列表一開始列為空
        m={}
        #層數一開始為0
        #列表的編號開始為0
        dfs(root,0,0,m)
        #同一層中,index最大減最小,再加一
        # 比如說 0,1,2,3就是(3-0)+1=4個節點距
        #然後再取最大值(即看每一層中,誰的節點距最大)
        return max(max(m[level])-min(m[level])+1 for level in m)
        