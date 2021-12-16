class Solution:
    def missingNumber(self, nums):
        return (1+len(nums))*len(nums)//2 -sum(nums)
#解題思路:
#包含missing number的總和-nums的總和=missing number
#又 包含missing number的總和:0,1,....,len(nums)
#所以  包含missing number的總和=(起始數字+結束數字)  *總共有幾個數字/2
#     包含missing number的總和=(    1   +len(nums))* len(nums)   //2