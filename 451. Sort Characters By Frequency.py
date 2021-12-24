from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        #value為字母出現的次數 key為字母
        #使用sorted函式排序,一般預設由小排到大,這邊設reverse=True表由大到小
        #key=lambda 設x:x[1] 
        #x[1]表示value,也就是字母出現的次數
        #由出現次數進行排序
        #再把key=字母 *出現的次數
        #有出現幾字就回傳幾次
        #用join把所有的字母串起來
        return ''.join(k * v for k, v in sorted(Counter(s).items(), key=lambda x:x[1],reverse =True))