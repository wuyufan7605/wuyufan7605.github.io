class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //加總全部數字
        int sum=accumulate(nums.begin(),nums.end(),0);

        int curSum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            //如果總和減某個數為現今總和的兩倍,表示某個數為pivot,即可回傳此數index
            if(sum-nums[i]==2*curSum) return i;
            //若不是,則現今總和就加上此數
            curSum+=nums[i];
        }
        //都不是就回傳-1
        return -1;
    }
};