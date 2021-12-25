class Solution:
    def jump(self, nums: List[int]) -> int:
        #jump為跳幾次
        #lastEnd為上次跳的最遠處
        #curEnd為現在跳到哪
        jump=lastEnd=curEnd=0
        n=len(nums)
        #針對每個數字
        for i in range(n-1):
            #在同一輪中,比較誰跳得比較遠
            #比如說:2,3,1,1,4
            #2最遠可跳到1,所以3,1為同一輪
            curEnd=max(curEnd,i+nums[i])
            #如果已經到這一輪的最遠距離
            #表示要再前進要再jump,所以jump+1
            #並將現在這個最遠距離的點,更新為上次跳的最遠的點,再繼續下輪
            if i==lastEnd:
                jump+=1
                lastEnd=curEnd
        #回傳跳幾次
        return jump
        