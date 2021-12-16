class Solution:
    def distributeCandies(self, candyType) -> int:
        return min(len(candyType)//2,len(set(candyType)))
    #全部有n個糖
    #因為只能吃n/2個
    #所以len(candyType)//2為可以吃的糖的個數
    #要看手上的糖有幾種
    #所以:len(set(candyType))=手上的糖有幾種
    #set在python中不會有重複的元素,所以用set
    #解題思路:
    #比如說手上有:[1,1,2,2,3,3]
    #->共有6顆糖,因為只能吃n/2顆,所以只能吃3顆
    #有1,2,3 共三種類的糖
    #所以最多可吃三種類的糖
    #有三種情形:
    #1.n/2>手上的糖有幾種
    #return手上的糖有幾種
    #比如說:可以吃4次,但只有3種糖,所以當然最多只能吃3種糖

    #2.n/2=手上的糖有幾種
    #return手上的糖有幾種
    #兩個數一樣,直接回傳

    #3.n/2<手上的糖有幾種
    #return n/2
    #比如說:可以吃2次,手上有3種糖,那最多也只能吃到2種糖