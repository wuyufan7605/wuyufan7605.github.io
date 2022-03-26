class MyQueue {
public:
    //初始化的資料結構
    MyQueue() {}
    
    //把資料push進queue的尾端
    void push(int x) {
       s1_.push(x); 
    }
    
    //將queue前端的資料移除,並return
    int pop() {
        if(s2_.empty()) move(); 
        int top=s2_.top();
        s2_.pop();
        return top;
    }
    
    //return queue的前端元素
    int peek() {
        if(s2_.empty()) move();
        return s2_.top();
    }
    
    //確認是否為空
    bool empty() {
        return s1_.empty() && s2_.empty();
    }
private:
    stack<int> s1_;
    stack<int> s2_;

    //把元素換到另一個stack,且元素順序反過來
    void move(){
        while(!s1_.empty()){
            s2_.push(s1_.top());
            s1_.pop();
        }
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */