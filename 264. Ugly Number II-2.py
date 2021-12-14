#使用heapq模組
#heapq是python的一個模組
#用來實作堆積佇列(heap queue=priority queue)
import heapq
class Solution:
    #為宣告類別時,會自動執行的函式
    #一般會拿來放基礎的屬性設定等
    def __init__(self):
        #第一個符合的數字為1
        num=[1]
        #設三個指針,針對質因數2,3,5
        p2=p3=p5=0
        for i in range(1690):
            tmp=min(num[p2]*2,num[p3]*3,num[p5]*5)
            num.append(tmp)
            
            if tmp==num[p2]*2:
                p2+=1
            if tmp==num[p3]*3:
                p3+=1
            if tmp==num[p5]*5:
                p5+=1
        self.num=num
                    
    def nthUglyNumber(self, n: int) -> int:
        #因為從0開始,所以回傳n-1
        return self.num[n-1]
