class LRUCache {
public:
    LRUCache(int capacity) {
        //把capacity存下來,之後會用到 
        capacity_=capacity;
    }
    
    int get(int key) {
        //看看有沒有我要的key
        const auto it=m_.find(key);
        //如果沒有這個key,就返回-1
        if(it==m_.cend()) return -1;
        
        //如果在LRU cache中有這個key,就把它移到最左邊
        //it->second是指現在只向的節點,把它移動到最前面(cache_.begin())
        cache_.splice(cache_.begin(),cache_,it->second);
        //最後返回這個key所對應的值
        return it->second->second;
    }
    
    void put(int key, int value) {
        //看看有沒有我要的key
        const auto it=m_.find(key);
        
        //如果有
        if(it!=m_.cend()){
            //更新這個值
            it->second->second=value;
            //然後移到最左邊,表示這個key最近被使用過了
            cache_.splice(cache_.begin(),cache_,it->second);
            return;
        }
        
        //如果這個key不存在
        
        //1.LRU cache滿了,移除最早的元素
        if(cache_.size()==capacity_){
            //把linked list中最尾端的元素(cache_.back())指給node
            const auto& node = cache_.back();
            //從mapping 表中把node的key刪掉
            m_.erase(node.first);
            //把linked list中最後的元素刪除掉
            cache_.pop_back();
        }
        
        //2.把新的元素,插入到最前面 
        //以emplace_front來創建一個新的節點
        cache_.emplace_front(key,value);
        //把這個key對應(map)到linked list的最前面
        m_[key]=cache_.begin();
    }
    
private:
    //capacity_表示LRU的容量
    int capacity_;
    //用list pair做cache_,第一個int是key,第二個是value
    list<pair<int,int>> cache_;
    //用hash tablle,前面的是key,後面的是一個指針(iterator)
    //以快速的訪問:某個key對應的linked list中的節點
    unordered_map<int,list<pair<int,int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */