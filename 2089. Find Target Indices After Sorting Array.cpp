class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //n為nums的長度
        int n=nums.size();
        //設一個vector叫output
        vector<int>output;
        //把nums的數字由小排到大
        sort(nums.begin(),nums.end());
        //如果有數字跟target依樣,就把index放進output
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                output.push_back(i);
            }
        }
        //回傳output
        return output;
    }
};