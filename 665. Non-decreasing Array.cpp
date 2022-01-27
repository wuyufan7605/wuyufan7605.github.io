class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        //cnt表示還有幾次可以改
        int cnt=1;
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                //若已經沒有次數可以改,就回傳false
                if(cnt==0){
                    return false;
                }
                //調降nums[i-1]
                if(i==1||nums[i]>=nums[i-2]){
                    nums[i-1]=nums[i];
                }
                //調升nums[i]
                else{
                    nums[i]=nums[i-1];
                }
                //調整次數減一
                cnt--;
            }
        }
        return true;
    }
};