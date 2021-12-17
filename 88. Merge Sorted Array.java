class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //表示index
        m--;
        n--;
        //因為題目有說nums1的長度為nums1的有效數字長+nums2的有效數字長
        //比如說:
        //num1=[4,5,7,0,0,0,0]
        //num2=[3,4,9,10]
        //也就是nums1的長度可以剛好容納nums2
        //nums1長度減一,因為從0開始(這裡是指index)
        //由num1最後一個數字開始比,逐漸往前比
        for(int i=nums1.length-1;i>=0;i--){
            //如果nums2沒有數字了,就返回
            if(n<0){
                return;
            } 
            //如果nums1還有數字,且num1目前的數字>=num2目前的數字
            //那就放num1目前的數字
            //然後m-1,因為第m個比過了,所以往m的前一個比
            if(m>=0 && nums1[m]>=nums2[n]){
                nums1[i]=nums1[m];
                m--;
                //剛好相反
                //如果num2的數字較大,就放nums2的數字
                //然後往nums2的前一個比
            }else{
                nums1[i]=nums2[n];
                n--;
            }
            
        }
    }
}