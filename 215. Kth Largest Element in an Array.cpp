class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //由小到大排好
        sort(nums.begin(),nums.end());
        //回傳遞k大的數字
        return nums[nums.size()-k];
    }
};