class MyStack:

    def __init__(self):
        #建立一個叫q的佇列
        self.q=deque()

    def push(self, x: int) -> None:
        #使用python的append函式,把x放進q中
        self.q.append(x)

    def pop(self) -> int:
        #除了q裡的最後一個,也就是我們要的那個
        for i in range(len(self.q) - 1):
            #把其餘的用python的popleft函式pop(拿)出來
            #並用剛剛寫的push函式,把pop出來的再放回去q後面
            self.push(self.q.popleft())
        #這樣我們要的就會在queue的最前端
        #直接把我們要的pop出去即可
        return self.q.popleft()

    def top(self) -> int:
        #回傳倒數第一個
        return self.q[-1]

    def empty(self) -> bool:
        #如果q裡面為空,就回傳True
        return len(self.q)==0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()