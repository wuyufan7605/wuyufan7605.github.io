#include <stdio.h>

int mySqrt(int x){
    if(x==1||x==0){
        return x;
    } 
    int l=1;
    int r=x;
    int ans=0;
    while(l<x||l==x){
        int m=l+(r-l)/2;
        if(m*m==x){
            return m;
        }
        if(m*m>x){
            r=m-1;
        }
        if(m*m<x){
            l=m+1;
            ans=m;
        }
    }
    
   return ans;
}