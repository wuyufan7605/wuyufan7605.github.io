class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N=len(points)
        #因為從0開始,所以到len(N)-1,因為range不包含N,所以到N
        #i: list of [cost,node]
        adj={i:[] for i in range(N)}
        #每個點跟其他點比,不跟自己比
        for i in range(N):
            #取得這個點的x,y座標
            x1,y1=points[i]
            for j in range(i+1,N):
                #取得要比較的那個點的座標
                x2,y2=points[j]
                #兩個點連線的edge成本
                dist=abs(x1-x2)+abs(y1-y2)
                #因為兩個點在無向圖連結,則兩個點互為彼此的鄰居
                #比如1 2連結
                #v1->2
                #v2->1
                adj[i].append([dist,j])
                adj[j].append([dist,i])
        #prim's
        #res代表total cost
        res=0
        #把拜訪過的存在visit中,用set就可以避免重複存相同的節點
        visit=set()
        minH=[[0,0]] #[cost,point]
        #只要還有節點還沒拜訪就繼續
        while len(visit)<N:
            #把min heap中cost最小的pop出來
            cost,i=heapq.heappop(minH)
            #如果已經拜訪過就不算,繼續
            if i in visit:
                continue
            #加上這個點的cost
            res+=cost
            #把這個點加進visit中,表示已經拜訪過
            visit.add(i)
            #對所有在相鄰串列中的節點
            for neiCost,nei in adj[i]:
                #如果還沒拜訪過
                if nei not in visit:
                    #就把這個點push到min heap中
                    heapq.heappush(minH,[neiCost,nei])
        #回傳總成本(total cost)
        return res