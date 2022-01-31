class Solution {
public:
    double myPow(double x, int n) {
        //如果是零次方,就回傳1
        if(n==0) return 1;
        //使用遞迴,half為目標次方的一半
        double half=myPow(x,n/2);
        //如果n為偶數
        if(n%2==0) return half*half;
        //如果n為正奇數
        if(n>0) return half*half*x;
        //如果n為負奇數
        return half*half/x;
    }
};