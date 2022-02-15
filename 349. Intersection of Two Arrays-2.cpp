class Solution {
public:
    //主程式
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //建一個set叫res
        unordered_set<int> res;
        //排序nums2
        sort(nums2.begin(),nums2.end());
        //每個在nums1的數字
        for(int a: nums1){
            //跟nums2做二元搜尋
            if(binarySearch(nums2,a)){
                //如果有在nums2中找到a的話,就把a放進res
                res.insert(a);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
    //二元搜尋之副程式
    bool binarySearch(vector<int> &nums,int target){
        int left=0,right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return true;
            else if (nums[mid]<target) left=mid+1;
            else right=mid;
        }
        return false;
    }
};