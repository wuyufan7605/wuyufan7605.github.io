class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #建一個queue
        q = []
        #用Counter數每個數字出現的個數,對每個數字進行迴圈
        for number, freq in Counter(nums).items():
            #如果queue中的數字個數已經到達題目要求(k)
            #就用python的heappushpop函式把出現最小次數的數字pop出去
            if len(q) == k:
                heappushpop(q, (freq,number))
            #如果還沒達到題目要求個數
            #就把這個次數及數字push進去
            else:
                heappush(q, (freq,number))
        #回傳queue中所有的數字
        #因為次數在前,數字在後
        #所以x[1]表數字
        #指回傳出數字即可
        return [x[1] for x in q]