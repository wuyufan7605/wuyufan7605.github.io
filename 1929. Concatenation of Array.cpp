class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        //len為nums的長度
        int len=nums.size();
        //創建一個vector叫ans,長度為nums的兩倍
        vector<int>ans(2*len,0);
        //從index0~len-1(也就是一一把nums的數字般進ans中)
        for(int i=0;i<len;i++){
            ans[i]=nums[i];
            //同時把nums中的數字一一再放到ans一次
            ans[i+len]=nums[i];
        }
        //回傳ans
        return ans;
    }
};