class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //使用c++  STL 標準函式庫中所提供的 sort 函數
        //需指定排序的起始與結束
        //預設為小到大排序
        sort(nums.begin(),nums.end());
        return nums;
    }
};