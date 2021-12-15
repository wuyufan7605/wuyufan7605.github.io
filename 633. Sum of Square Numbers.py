class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        left,right=0,int(c**0.5)
        while left<=right:
            cur=left*left+right*right
            if cur<c:
                left+=1
            elif cur>c:
                right-=1
            else:
                return True
        return False