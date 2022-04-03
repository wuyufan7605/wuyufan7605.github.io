class Solution {
public: 
    int climbStairs(int n) {
        int stairs[50]={0,1,2};
        if(n<=2) return n;
        else{
            if(stairs[n-1]==0) stairs[n-1]=climbStairs(n-1);
            if(stairs[n-2]==0) stairs[n-2]=climbStairs(n-2);
            return stairs[n-1]+stairs[n-2];
        }
      
    }
};