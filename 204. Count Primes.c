//sieve of eratosthenes (埃拉托斯特尼筛法)
int countPrimes(int n){
    int res=0;
    bool pr[n+1];
    //先全設為true
    for(int i=0;i<n+1;i++){
        pr[i]=true;
    }
    //把合數都設為false
    for(int i=2;i*i<n||i*i==n;i++){
        if(pr[i]){
             for(int j=i*i;j<n||j==n;j+=i){
                 pr[j]=false;
              }
        }
    }
    //從2開始算有幾個質數
    //因為題目要比n小的質數
    //所以從2到n-1
    for(int i=2;i<n;i++){
        if(pr[i]){
            res++;
        }
    }
   
    return res;
}