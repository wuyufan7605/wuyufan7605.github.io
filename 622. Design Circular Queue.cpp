class MyCircularQueue {
public:
    //front為queue中的front
    //rear為queue中的rear
    //sz為循環柱列(circular queue)中的最大size
    //len為queue中現在的長度
    int front,rear,sz,len=0;
    
    //設一個vector
    //vector為c++中的一個class,可視為自動擴展容量的陣列
    //有很多好用的function
    //像是vec.inser(),可插入一個或多個元素至vector內任意位置
    vector<int> CirQue;
    
    MyCircularQueue(int k) {
        //設定預設值
        sz=k;
        front=0;
        rear=0;
        
        //一開始queue裡都設為-1
        //vectorname.assign(int size, int value)
        //k為queue的大小,-1為裏頭的值
        CirQue.assign(k,-1);
    }
    
    bool enQueue(int value) {
        //如果滿了,回傳false
        if(isFull()){
            return false;
        }
        
        //如果沒滿,就enqueue
        //插入新數字,現在長度加一
        len++;
        
        //在尾端插入數字
        CirQue[rear]=value;
        
        //尾端的位置加一
        rear++;
        //因為是circular queue
        //所以在超出界線,最尾端時要讓它回到0的位置
        //比如說
        //index 0 1 2
        //value 7 8 6 這時rear=3
        //sz=3 即預設長度為3
        //所以3/3餘0 回到最初起點位置
        //即使是一般的插入也一樣
        //比如說
        //index  0 1 2
        //value  7 8
        //如果要再插入一個數字
        //rear++ rear變成2
        //rear=rear%sz rear=2%3=2
        //所以再插入一個數字,rear變3
        rear%=sz;
        
        return true;
    }
    
    bool deQueue() {
        //如果是空的,就沒辦法刪
        //回傳false
        if(isEmpty()){
            return false;
        }
        //如果可以刪
        //長度會少一
        len--;
        
        //因為FIFO(先進先出),所以先刪front位置的值
        //把值設成預設的-1
        CirQue[front]=-1;
        //因為circular queue所以這樣寫
        //比如說要刪一個值
        //index  0               1      2
        //value  7               8      9
        //       next-front      rear   front
        //front=2, (2+1)%3=0
        //所以下一個front位置為0
        front=(front+1)%sz;
        
        return true;
    }
    
    int Front() {
        //如果是空的,回傳預設值-1
        if(isEmpty()){
            return -1;
        }
        //回傳front位置的值
        return CirQue[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        //index為rear的前一個位置
        int index = rear-1;
        //因為circular queue所以這樣寫
        
        if(index<0){
            index=index+sz;
        }
        
        return CirQue[index];
    }
    
    bool isEmpty() {
        //如果長度為0
        //就是空的
        if(len==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        //如果現在長度跟最大長度相同
        //就滿了
        if(len==sz){
             return true;
        }
        return false;   
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */