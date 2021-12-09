//寫一個函式追蹤左右兩邊的數字
//i為陣列最左邊的次序(index),通常為0
//j是最右邊數字的次序,為陣列長度-1,因為陣列從0開始編號
int dfs(int* nums,int i,int j){
    //如果最左跟最右一樣,即只有一個數字,回傳唯一的那個數字
    if(i==j){
        return nums[i];
    }
    //中間數為兩邊和除以二
    int m=(i+j)/2;
    //分別向左邊及右邊做追蹤
    int left=dfs(nums,i,m);
    int right=dfs(nums,m+1,j);
    //如果左邊的數字等於右邊的數字
    //則回傳這個一樣的數字
    if(left==right)return left;
    //如果左邊這個數的數量>右邊數的數量,就回傳左邊的數
    //否則回傳右邊的數
    return count(nums,i,m,left)>count(nums,m+1,j,right)?left:right;
    
}
//寫一個函式計算陣列中,這個數字出現幾次
int count(int* nums,int i,int j,int c){
    int res=0;
    for(int k=i;k<j||k==j;k++){
        if(nums[k]==c){
            res++;
        }
    }
    return res;
}
int majorityElement(int* nums, int numsSize){
    
    return dfs(nums,0,numsSize-1);
}