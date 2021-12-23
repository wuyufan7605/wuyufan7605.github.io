"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        #key為原本的節點,value為clone的節點
        #key在前,value在後
        #都設None,表若為空,就返回空節點
        self.visit={None:None}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        #如果這個節點已經在拜訪過的list中,就直接回傳
        if node in self.visit:
            return self.visit[node]
        #增加node值的節點,且它的鄰居為空,即[].存到res
        res=Node(node.val,[])
        #把res存到拜訪過的list中
        self.visit[node]=res
        #如果有鄰居
        if node.neighbors:
            #把這個點的所有鄰居,都做cloneGraph函式,即全部clone到res
            res.neighbors=[self.cloneGraph(n) for n in node.neighbors]
        return res