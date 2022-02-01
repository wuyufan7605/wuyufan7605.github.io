class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        while(x!=0){
            //避免overflow/underflow
            if(abs(reverse)>214748364) return 0;
            reverse=reverse*10+x%10;
            x/=10;
        }
        return reverse;
    }
};