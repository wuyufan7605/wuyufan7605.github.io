class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1,b1=map(int,num1[:-1].split('+'))
        a2,b2=map(int,num2[:-1].split('+'))
        return '%d+%di' % (a1*a2-b1*b2,a1*b2+b1*a2)