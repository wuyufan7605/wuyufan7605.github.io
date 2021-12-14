#使用heapq模組
#heapq是python的一個模組
#用來實作堆積佇列(heap queue=priority queue)
import heapq
class Solution:
    #為宣告類別時,會自動執行的函式
    #一般會拿來放基礎的屬性設定等
    def __init__(self):
        #用來放1690個:所有質因數為2或3或5的數
        self.num = []
        #python可以用{}存資料,資料可以是任何型態
        #{}叫dictionary(字典)
        #第一個數為1
        #s用來存質因數為2或3或5的數
        s={1,}
        q=[]
        #把1放進q這個heap(priority queue)中
        heapq.heappush(q,1)
        for i in range(1690):
            #取出heap中最小的值,並存到cur中
            cur=heapq.heappop(q)
            #把cur存到num這個串列中
            self.num.append(cur)
            for j in [2,3,5]:
                #  tmp變數=已經存進num串列數字*2
                #及tmp變數=已經存進num串列數字*3
                #及tmp變數=已經存進num串列數字*5
                tmp=cur*j
                #如果乘積跟前面已經存的數不重複的話
                #就存進s
                #s再push進q這個heap中
                if tmp not in s:
                    s.add(tmp)
                    heapq.heappush(q,tmp)
                    
    def nthUglyNumber(self, n: int) -> int:
        #因為從0開始,所以回傳n-1
        return self.num[n-1]