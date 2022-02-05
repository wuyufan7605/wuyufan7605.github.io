class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0){
            //num減掉奇數(由1開始)
            num-=i;
            //每次都加二(因為要奇數)
            i+=2;
            //全由奇數構成即為平方數
            if(!num) return true;
        }
        return false;
    }
};