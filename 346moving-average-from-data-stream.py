from typing import Deque


class MovingAverage:

    def __init__(self,size:int):
        #size為有幾個數字
        self.size=size
        #建立一個雙向佇列q
        #即可從兩端插入或移除
        self.q=deque()
        #把目前有幾個數字設為0
        self.count=0
        #先把總和設為0
        self.sum=0

    def next(self,val:int)->float:
        #每加一個數字就+1,表又多一個數字
        self.count+=1
        #把數字push(放)進佇列中
        self.q.append(val) 
        #tail為最先放進來的數
        #如果新的數字加進來,已經超過size,就把最先開始的數字pop掉
        tail=self.q.popleft() if self.count> self.size else 0
        #總和為上一個總和-pop掉的數字+新放進來的數字
        self.sum=self.sum-tail+self.val
        #然後取平均
        #分母取最小值
        #因為當心數字加進來,count會超過size
        #佇列還沒滿時,要以count算
        #考慮到兩種情況,所以用min
        return self.sum/min(self.size,self.count)

