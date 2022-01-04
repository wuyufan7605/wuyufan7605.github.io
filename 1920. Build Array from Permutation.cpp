class Solution {
public:
    //建ans 大小跟nums依樣
    vector<int> buildArray(vector<int>& nums) {
        //l為nums的長度
        int l=nums.size();
        //ans跟nums的長度依樣,由0開始
        vector<int>ans(l,0);
        //由nums中依序找ans[i],並放進ans
        for(int i=0;i<l;i++){
            ans[i]=nums[nums[i]];
        }
        //回傳ans
        return ans;
    }
};