class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //設一個vector叫做runningsum
        vector<int>runningsum;
        //把nums第一個數字放進runningsum
        runningsum.push_back(nums[0]);
        //把上一個總和+新的數字 就是新的總和
        for(int i=1;i<nums.size();i++){
            runningsum.push_back(nums[i]+runningsum[i-1]);
        }
        //回傳runningsum
        return runningsum;
    }
};