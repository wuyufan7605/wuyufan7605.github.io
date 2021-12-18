class Solution:
    def isAlienSorted(self, words, order):
        #enumerate()為python的函式
        #可以將數字們組合成:列表 字串符 元組
        #格式:enumerate(sequence, [start=0])
        #c為index,i為value
        #把order裡的字母存進dic中
        dic = {c:i for i,c  in enumerate(order)}
        #range函式布包刮最後那個數
        #由零開始
        #利用for迴圈,比較倆倆數字
        #有點像bubble sort那樣,不過這裡不用跑n次
        for i in range (len(words)-1):
            word1 = words[i]
            word2 = words[i+1]
            #若兩個字裡的字母不同,且前面的較大,就false,同時離開迴圈
            for k in range(min(len(word1),len(word2))):
                if word1[k]!=word2[k]:
                    if dic[word1[k]]>dic[word2[k]]:
                        return False
                    break
            #如果不是上述,也就是可能出現一個字包住另一個的情況
            #比如說:apple ,app
            #如果前面的字長度較大,就false
            else:
                if len(word1)>len(word2):
                    return False
        return True
            