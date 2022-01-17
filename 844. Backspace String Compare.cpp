class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        //處理s的pop(#的時候)及push
        for(char c:s){
            if(c!='#'){
                s1.push(c);
            }else{
                if(!s1.empty()){
                    s1.pop();
                }
            }
        }
        //處理t的pop(#的時候)及push
        for(char c:t){
            if(c!='#'){
                s2.push(c);
            }else{
                if(!s2.empty()){
                    s2.pop();
                }
            }
        }
        //確認s跟t刪掉元素後,是否一致
        while(!s1.empty()&&!s2.empty()){
            char c1=s1.top();
            s1.pop();
            char c2=s2.top();
            s2.pop();
            
            if(c1!=c2) return false;
            
        }
        //如果有一個為空,表示長度不一
        if(!s1.empty()||!s2.empty()) return false;
        //剩下的情況就都是true了
        return true;
    }
};