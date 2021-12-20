class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def dfs(x,y,index):
            #把現在的點加到q這個list中
            q=[(x,y)]
            #visit表示訪問過的點  
            visit={(x,y)}
            #當q不為空時
            while  q:
                #python3的list有很多好用的操作方法
                #pop是其中之一
                #會移除指定的元素
                #如果沒有指定元素,它會移除lilst中最後一個元素並回傳
                curx,cury=q.pop()
                #給現在的島嶼編號
                grid[curx][cury]=index
                for dx,dy in directions:
                    tx,ty=curx+dx,cury+dy
                    #如果移動的位置在矩陣內,且移動的位置裡的值為1
                    if 0<=tx<n and 0<=ty<n and grid[tx][ty]==1:
                        #就加到q及visit(已經拜訪過的)中
                        q.append((tx,ty))
                        visit.add((tx,ty))
             #回傳拜訪過的個數,即為島的長度
             return len(visit)
                        
                    
        #求出矩陣的長跟寬一樣
        n=len(grid)
        #四個方向:上 下 左 右
        directions=[(0,1),(0,-1),(1,0),(-1,0)]
        #area是一個字典,用來存每一個島的面積 
        area={}
        #給每一個島附一個序號,這個序號從2開始
        index=2
        for i in range(n):
            for j in range(n):
                #如果這個點的值是1的話
                #就dfs,去找上下左右是否有相連的島,並算出這個島的面積
                if grid[i][j]==1:
                    area[index]=dfs(i,j,index)
                    #現在這個島的面積算完
                    #就要算下一個島
                    #所以編號+1
                    index+=1 
        #結果就是最大島的面積,或是0
        #0就表示所有的島都是空的
        #要寫這一行是因為會有都是1的情形
        #下面那一大串沒辦法表示都是1的情形
        res=max(area.values() or [0])
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]==0:
                    #把與現在島相連的編號,放到這個tmp裡
                    tmp=set()
                    for dx,dy in directions:
                        #上下左右移動
                        tx,ty=i+dx,j+dy
                        #如果grid[tx][ty]>1,表示有島嶼,因為我編號設定從2開始
                        if 0<=tx<n and 0<=ty<n and grid[tx][ty]>1:
                            tmp.add(grid[tx][ty])
                    res=max(res,sum(area[t]for t in tmp)+1)
        return res
