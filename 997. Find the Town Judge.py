class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        #用ct表示每個人的進跟出
        ct=[0]*(n+1)
        #對每個在列表的人
        for x,y in trust:
            #因為是x相信y,所以x->y,x+1,y-1
            ct[x]-=1
            ct[y]+=1
        #對所有的人
        #python3包含前面(1),不包含後面(n+1)
        for i in range(1,n+1):
            #如果進跟出的總和為n-1,就是法官
            #因為其他人都相信他,所以+n-1(扣掉法官自己)
            #又因為法官不相信任何人(題目規定),所以沒有出去的數
            if ct[i]==n-1:
                return i
        #都沒有就表示找不到法官
        return -1