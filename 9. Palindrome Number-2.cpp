class Solution {
public:
    bool isPalindrome(int x) {
        //負數為false
        if(x<0) return false;
        
        //初始化
        long int x_reverse=0;
        int x_origin=x;
        
        //計算反轉的字串
        while(x){
            x_reverse=x_reverse*10+x%10;
            x/=10;
        }
        //比較原本的跟反轉的是否相同
        return x_origin == x_reverse;
    }
};