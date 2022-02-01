class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //一個一個數字檢查
        for(int i=0;i<nums.size();i++){
            //如果數字比target大或等於,就安插在這
            if(nums[i]>=target){
                return i;
            }
        }
        //都沒有,就安插在最後面
        return nums.size();
    }
};