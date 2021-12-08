#寫一個函式判斷第i號位置要不要選
#比如說  0, 1, 2  ->i號位置
#      [3, 4, 5]  ->輸入的數字
def dfs(nums,i,choices,results):
    #設一個條件,讓程式不要一直跑個不停
    if(len(nums)==i):
        #印出要或不要(測試用)
        #print(choices) 
        
        #先新增一個空陣列r
        #有幾個選擇,即有幾個數字,就跑幾次迴圈
        #把第k個位置的選擇放進r陣列裡
        r=[]
        for k in range(len(choices)):
            if choices[k]:
                r.append(nums[k])
        #再把r陣列放進results陣列中
        results.append(r)
        return
    #下一輪要
    dfs(nums,i+1,(*choices,True),results)
    #下一輪不要
    dfs(nums,i+1,(*choices,False),results)
    

class Solution:
    def subsets(self, nums):
        results=[]
        dfs(nums,0,[],results)
        return results
        