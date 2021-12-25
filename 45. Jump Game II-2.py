class Solution:
    def jump(self, nums: List[int]) -> int:
        #res為跳的次數
        res=0
        #利用左右指針框出每輪的範圍
        l=r=0
        #只要又指針在範圍內
        while r<len(nums)-1:
            #每輪的最遠index都重新定義,因為每輪都不一樣
            farthest=0
            #在左右指針中
            for i in range(l,r+1):
                #不停更新最遠的數字的index
                farthest=max(farthest,i+nums[i])
            #更新完,左右指針移至下一輪的範圍,比如說:
            #2,3,1,1,4     
            #[2][3,1][1,4]   //2為一輪 3,1為一輪 1,4為一輪 用[]框起來表示
            #    l r         //原本l=3,r=1
            #[2][3,1][1,4]
            #         l r    //下一輪l=1,r=4
            #所以下一輪的r=原本l+1
            #下一輪r=上一輪的最遠的數字
            l=r+1
            r=farthest
            #然後要去下一輪,表示又跳一次,res+1
            res+=1
        return res