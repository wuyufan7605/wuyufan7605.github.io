class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //nums1用set表示,才不會重複比較
        unordered_set<int> n(nums1.begin(),nums1.end());
        vector<int>ans;
        //所有nums中的數字,看有沒有跟nums1重複
        for(int num:nums2){
            //沒有重複的數字的話,就略過後面兩行,直接return ans
            if(!n.count(num)) continue;
            //有重複的話,push進ans
            ans.push_back(num);
            n.erase(num);
        }
        return ans;
    }
};