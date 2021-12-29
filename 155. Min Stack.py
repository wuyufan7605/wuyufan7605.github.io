class MinStack:

    def __init__(self):
        #建兩個stack
        #一個放輸入的值
        #一個放目前為止,最小的值
        self.stack=[]
        self.minStack=[]

    def push(self, val: int) -> None:
        #把要push的值push(放)進stack中
        self.stack.append(val) 
        #要push的值,跟上一回最小值做比較,取比較小的那個
        #放進(push)minStack
        val=min(val,self.minStack[-1] if self.minStack else val)
        self.minStack.append(val)

    def pop(self) -> None:
        #把兩個stack中,要pop的值給pop出來
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        #回傳stack中最後一個,即為最上面那個
        return self.stack[-1]

    def getMin(self) -> int:
        #回傳minStack中最上面那個值
        #表示現在最小的值
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()