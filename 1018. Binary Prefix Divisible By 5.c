/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize){
    //把二進制轉換成我們常用的十進制
    //num表示十進制數字,一開始設成0
    int num=0;
    //output表示結果(是否是5的倍數)
    //因為輸入的數字有numsSize個,所以輸出結果也有numsSize個
    bool *output = malloc(numsSize * sizeof(bool));
    *returnSize = numsSize;
    
    
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){
            num=num*2+1;
        }else{
            num=num*2;
        }
        if(num%5==0){output[i]=1;}
        if(num%5!=0){output[i]=0;}
        //節省記憶體空間,避免overflow
        //以7跟15說明
        //7%5==2
        //下一輪迴圈num=2*2+1==5
        //7=5*1+2
        // 下一輪的數字是7      *2+1
        //             =(5*1+2)*2+1
        //             = 5*1*2+2*2+1
        //        所以我只要證明2*2+1是5的倍數即可
        //因為前項(5*1*2)即後項(2*2+1)都有5為公因數,就一定是5的倍數
        num=num%5;
    }
    return output;
}