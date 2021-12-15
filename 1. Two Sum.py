class Solution:
    def twoSum(self, nums, target: int):
        #設一個字典
        dic={}
        #enumerate()為pyhthon之函式,以此為例,可對應到nums
        #i表key(就像c裡面的index),就是第幾個的意思
        #n是第i個表示的數,也就是value
        for i,n in enumerate(nums):
            #如果目標減掉現在這個數=某個數
            #某個數如果不在字典,就把減數放到dic
            #如果在dic裡面,回傳某個數的key,及現在這個數的key
            if target-n in dic:
                return [dic[target-n],i]
            dic[n]=i