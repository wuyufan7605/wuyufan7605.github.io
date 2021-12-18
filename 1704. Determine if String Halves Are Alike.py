import collections
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        #算出字串一半的長度
        l=len(s)//2
        #back表示後半有幾個字母
        #front表示前半有幾個字母
        back=Counter(s[:l].lower())
        front=Counter(s[l:].lower())
        b=0
        f=0
        #當前半有母音(a,e,i,o,u),f就+1
        #當後半有母音(a,e,i,o,u),b就+1
        #back,front雖然為前半及後半字串的個數
        # 但也可直接當前半及後半使用
        for u in ('a','e','i','o','u'):
            b+=back[u]
            f+=front[u]
        #當後半及前半,母音個數相同時,回傳
        return b==f