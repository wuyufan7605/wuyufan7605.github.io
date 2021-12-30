class Solution:
    def fib(self, n: int) -> int:
        if n==0:
            return 0
        if n<=2:
            return 1
        #f1,f2設為1
        f1=1
        f2=1
        #從n=3開始算
        #f1,f2一起算,所以寫在同一行
        #如果分開寫就會錯
        for i in range(2,n):
            f1,f2=f2,f1+f2
        #回傳結果
        return f2