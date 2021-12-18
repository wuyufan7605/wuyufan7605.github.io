class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        #按照長度大小排好
        #比如說有: a,abc,ba,abdc
        #會排成:   a,ba, abc,abdc
        words.sort(key=lambda word:len(word))
        #設一個字典,專門存每個字在:符和包含前綴字情形下的對應的長度
        dic={}
        #把res一開始設成0
        res=0
        #對於每個在輸入(words)中的字
        #利用迴圈一個一個比
        for word in words:
            #每個字至少一個鏈結(題目規定)
            cur=1
            #對每個字,一個一個字母比對
            for i in range(len(word)):
                #把比對的那個字母拿掉,其他的字母就存在tmp中
                tmp=word[:i]+word[i+1:]
                #如果tmp在dic中
                if tmp in dic:
                    #用現在的鏈結和之前的鏈結比
                    #取較大的那個
                    cur=max(cur,dic[tmp]+1)
            #針對不同字之間,進行比較,看哪個字的鏈結最多
            res=max(res,cur)
            #把每個字及鏈結存進dic中
            dic[word]=cur
        #回傳最大鏈結數
        return res