class Solution:
    def minCut(self, s: str) -> int:
        #n為字串的長度,表示有幾個字
        n=len(s)
        #cut[i]表示i個數字要切割幾次
        #這邊先初始化,以i-1表示
        #因為i-1為最多次數的切割方式
        #到n+1,因為python不包含最後一個,也就是只到n,從0開始
        cut=[i-1 for i in range(n+1)]
        #i表示list中數字的index,從0開始,到n-1
        for i in range(n):
            j=0
            #奇數個數字的算法
            #當左右兩邊都在list內,且左右兩邊相同,確認回文
            #一開始由index=0的數字當中間值,由0開始不斷增加,向兩邊確認是否回文
            #且同時在向左右部段增加時,藉由不斷更新可能的切法數
            #跟上一次比哪次切法數最小,不斷更新
            while i-j>=0 and i+j<n and s[i-j]==s[i+j]:
                cut[i+j+1]=min(cut[i+j+1],cut[i-j]+1)
                j+=1
            j=1
            #偶數個數字的算法
            #邏輯跟奇數的一樣
            while i-j+1>=0 and i+j<n and s[i-j+1]==s[i+j]:
                cut[i+j+1]=min(cut[i+j+1],cut[i-j+1]+1)
                j+=1
        return cut[n]