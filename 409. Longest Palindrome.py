from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        #使用Counter函式計算每個字母出現的次數
        ct=Counter(s)
        #結果先設為零
        res=0
        #如果出現次數,就將f改為1
        #一開始先設為0
        f=0
        #對所有次數
        for v in ct.values():
            #如果是偶數次
            if v%2==0:
                #直接加進去
                res+=v
            #奇數次就減一再加,因為要偶數個
            #然後把f改成1
            else:
                res+=v-1
                f=1
        return res+f