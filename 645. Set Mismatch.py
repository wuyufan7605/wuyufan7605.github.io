class Solution:
    def findErrorNums(self, nums) :
        #nums為輸入的數字,比如說:[1,2,2,4]
        #unique_num_sum為"沒有重複數字的總和"
        unique_num_sum=sum(set(nums))
        #dup為重複的數字
        dup=sum(nums)-unique_num_sum
        #missing為缺失的那個數字
        missing=(1+len(nums))*len(nums)//2 -unique_num_sum
        #回傳這兩個數
        return [dup,missing]
#重複的數字=nums總和-沒有重複數字的總和
#以[1,2,2,4]為例:
#重複的數字=nums總和 -沒有重複數字的總和
#         =(1+2+2+4)-(1+2+4)

#缺失的那個數字=正確數字的總和-沒有重複數字的總和
#又 因為"正確數字的總和"為1~n的數字
#所以利用梯形公式=(上底+下底) *高/2 來算正確的總和
#以[1,2,2,4]為例:
#缺失的那個數字=正確數字的總和-沒有重複數字的總和
#            =(1+2+3+4)-(1+2+4)=3
        