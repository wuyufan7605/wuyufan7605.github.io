class Solution:
    def maxArea(self, height: List[int]) -> int:
        #一開始把結果設為0
        res=0
        #一開始設左右指針
        #左指針指向0
        #右指針指向最後一個數
        l,r=0,len(height)-1
        #移動長度較小的那個
        #只要兩個指針還沒相交就繼續
        while l<r:
            #(r-l)為寬,min(height[l],height[r])指取短的一邊當長方形的高
            #這次的面積跟上次的面積比,取大的
            res=max(res,(r-l)*min(height[l],height[r]))
            #如果左>右,右向裡面移動一格
            if height[l]>height[r]:
                r-=1
            #如果左<右,左往右移動一格
            else:
                l+=1
        #回傳結果(最大面積)
        return res