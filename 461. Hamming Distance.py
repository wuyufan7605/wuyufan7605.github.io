#定義一個函式來找兩個二進制數字的不同
def hammingDistance(x, y):
    #bin是python內建的函式,用來轉換成二進制
    #加上2的32次方
    #目的是為了統一個數,方便比較
    #比如說:1跟4
    # 2:1  ->Xb10000000000000000000000000001
    # 4:100->Xb10000000000000000000000000100
    #由於前三個依樣(0,1,2),所以從陣列編號3開始比
    sx=(bin(x+2**32))
    sy=(bin(y+2**32))
    #c語言因沒有內建函式,所以要用下面的方法轉換進制
   # digits=[]
   # while x>0:
   #     digits.append(x%2)
   #     x=x//2
   #digits.reverse
   #print(digits)
    diff=0
    #從陣列編號3開始比
    #美找到一個不同,變數diff加一
    for i in range(3,len(sx)):
        if sx[i]!=sy[i]:
            diff+=1
    return(diff)
    
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return hammingDistance(x, y)
        