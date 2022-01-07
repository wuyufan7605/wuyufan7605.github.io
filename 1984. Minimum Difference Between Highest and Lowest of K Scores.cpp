class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        //先把差設成最大
        int minDiff=INT_MAX;
        //n為nums的長度
        int n=nums.size();
        //排序nums(由小到大)
        sort(nums.begin(),nums.end());
        for(int i=0;i+k-1<n;i++){
            //選取k個數字,不斷比較,選出差最小的
            if(nums[i+k-1]-nums[i]<minDiff){
                minDiff=nums[i+k-1]-nums[i];
            }
        }
        //回傳最小的差
        return minDiff;
    }
};