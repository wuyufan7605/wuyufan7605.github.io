class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #建立左右指針
        #代表numbers的index
        #左指針為最左邊,即0
        #又指針為最右邊,所以為長度減一,因為從0開始
        l,r=0,len(numbers)-1
        #只要左指針小於右指針(才不會重複算)
        while l<r:
            #把左右指針指向的數字相加
            curSum=numbers[l]+numbers[r]
            #如果比目標大,右指針向內移動
            if curSum>target:
                r-=1
            #如果比目標小,左指針向右移動
            elif curSum<target:
                l+=1
            #如果相等,回傳左右指針加一
            #因為題目不是從0開始,是從1開始
            else:
                return [l+1,r+1]
        return []