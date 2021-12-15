class NumArray:

    def __init__(self, nums):
        #定義一個叫prefix_sum的list
        #裡面先放一個0
        #為了方便設計
        #設計理念:現在這一項+前面一項
        #比如說:
        #index       0  1  2  3
        #value       0 -2  0  3
        #prefix_sum  0 -2 -2  1
        #prefix_sum為前綴和=prefix_sum前一項+原本list現在這一項的值
        #prefix_sum[0]=0 (已經先放進去了)
        #prefix_sum[1]=0+(-2)=-2
        #prefix_sum[2]=-2+0=-2
        #prefix_sum[3]=-2+3=1
        self.prefix_sum=[0]
        #self.prefix_sum[-1]表示list中最後一項
        #最後一項=前幾項的和
        #因為算過了,所以直接拿來用,不用再算一次
        #最後一項+現在這項的值=現在這項的前綴和
        for n in nums:
            self.prefix_sum.append(self.prefix_sum[-1]+n)
        

    def sumRange(self, left: int, right: int) -> int:
        #因為加了個0,所以right+1
        #比如說:
        #index           0  1  2  3  4  5  
        #value          -2  0  3 -5  2 -1
        #index        0  1  2  3  4  5  6
        #prefix_sum   0 -2 -2  1 -4 -2 -3
        #要求本來list中第1項~第5項的前綴和=prefix_sum[5+1]-prefix_sum[1]
        #右減左 ,舉例說明:
        #index           0  1  2  3   
        #value          -2  0  3 -5 
        #index        0  1  2  3  4  
        #prefix_sum   0 -2 -2  1 -4 
        #要求本來list中第2項~第3項的前綴和=3-5=-2
        #也就是prefix_sum[3+1]   - prefix_sum[2]
        #    =(0+ -2+ -2 +1+ -4)- (0 + -2 + -2)
        #因為右邊有重複累加到左邊的,所以直接減即可
        return self.prefix_sum[right+1]-self.prefix_sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)