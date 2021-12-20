class Solution:
    def findLHS(self, nums: List[int]) -> int:
        #用計數器算每個數字出現的個數
        c=Counter(nums)
        #先把結果設為0
        res=0
        #對所有出現在計數器裡的數字x
        for x in c:
            #如果下一個數字也在計數器裡
            #就把兩個相差1的數字,出現的次數加總
            #每次的總和,都跟上一輪的比較,取較大的那個
            if x+1 in c:
                res=max(res,c[x]+c[x+1])
        #等同於所有加總的數字都比較過
        #回傳最大的那個
        return res