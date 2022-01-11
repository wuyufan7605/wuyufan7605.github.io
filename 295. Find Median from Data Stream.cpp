class MedianFinder {
public:
    MedianFinder() { }
    
    //把數字一個個加進l_或r_兩個heap中
    //並調整兩個heap的平衡
    void addNum(int num) {
        //把數字小的放在l_中
        //其他大的放在r_中
        if(l_.empty()||num<=l_.top()){
            l_.push(num);
        }else{
            r_.push(num);
        }
        //調整兩個heap的平衡
        //也就是l_的數量==r_的數量
        //頂多因為奇數的關係
        //l_多r_一個
        if(l_.size()<r_.size()){
            l_.push(r_.top());
            r_.pop();
        }else if(l_.size()-r_.size()==2){
            r_.push(l_.top());
            l_.pop();
        }
    }
    
    double findMedian() {
        //奇數個回傳l_的top
        if(l_.size()>r_.size()){
            return static_cast<double>(l_.top());
        }else{
            //偶數個:回傳l_top跟r_top的平均值
            return (static_cast<double>(l_.top())+r_.top())/2;
        }
    }
//定義兩個heap
//左邊為max-heap
//右邊為min-heap
private:
    priority_queue <int, vector<int>,less<int>> l_;    //max_heap
    priority_queue <int, vector<int>,greater<int>> r_; //min-heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */