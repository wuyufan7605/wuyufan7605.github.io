class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        #使用collections.defaultdict就不用擔心沒有key值,系統會塞預設值進去key,程式碼會比較簡潔
        edges=collections.defaultdict(list)
        #把所有的路徑存進edges中
        for u,v,w in times:
            edges[u].append((v,w))
        #把起點先放進minHeap中
        minHeap=[(0,k)]
        #用set就部會重複存走過的點
        visit=set()
        #先把現在總路徑長設為0
        cur_path=0
        while minHeap:
            #把目前為止最小路徑的點pop出來
            w1,n1=heapq.heappop(minHeap)
            #如果已經拜訪過了,就繼續
            if n1 in visit:
                continue
            #如果還沒拜訪過,那現在拜訪了,所以加進visit中
            visit.add(n1)
            #上一回跟這一回的路徑誰大,就更新誰
            cur_path=max(cur_path,w1) 
            
            #BFS
            #n1是現在所在的這個點
            for nei,nei_weight in edges[n1]:
                if nei not in visit:
                    #把weight放前面,因為要選weight最小者
                    heapq.heappush(minHeap,(w1+nei_weight,nei))
        return cur_path 
            
            
