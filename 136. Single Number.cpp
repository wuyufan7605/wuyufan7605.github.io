class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            //做XOR,留下只出現一次的數字
            ans=ans^nums[i];
        }
        //回傳只出現一次的數字
        return ans;
    }
};