class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #給s跟t各自建一個字典
        #放s跟t個字母的出現次數
        #key為字母,value為出現次數
        CountC={}
        CountT={}
        #如果兩個字串長度不同,回傳false
        if len(s)!=len(t):
            return False
        #從index 0~長度減一
        #即所有s的字母都跑一遍
        for i in range(len(s)):
            #算s跟t各字母的出現次數
            #使用python3的get函式
            #為了避免s裡面沒東西,會出現錯誤訊息
            CountC[s[i]]=1+CountC.get(s[i],0)
            CountT[t[i]]=1+CountT.get(t[i],0)
        #對每個出現在s中的字母
        for c in CountC:
            #如果s有一個字母出現次數跟t對不上
            #回傳false
            if CountC[c]!=CountT.get(c,0):
                return False
        return True