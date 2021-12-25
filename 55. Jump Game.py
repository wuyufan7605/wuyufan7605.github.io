class Solution:
    def canJump(self, nums: List[int]) -> bool:
        #把最後一個數的index設為goal
        goal=len(nums)-1
        #由後往前推,直到index為0
        for i in range(len(nums)-2,-1,-1):
            #只要前一個數可以到達後一個數
            #就把目標往前設
            if i+nums[i]>=goal:
                goal=i
        #如果可行,就回傳True,不行就False