class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap; //哈希表,紀錄nums2中各個元素的下一個更大的元素
        stack<int> sta; //堆疊
        
        //獲取nums2中每個元素的下一個更大元素
        for(int i=0;i<nums2.size();i++){ //遍歷num2的每個元素
            while(!sta.empty() && nums2[i]>sta.top()){ //紀錄下一個更大元素於hashmap中
                hashmap[sta.top()]=nums2[i];
                sta.pop();
            }
            sta.push(nums2[i]); //把當元素push進stack中
        }
        
        //找stack中剩餘元素,因不存在下一個更大的元素,所以hashmap都填入-1
        while(!sta.empty()){
            hashmap[sta.top()]=-1; 
            sta.pop();  //把已填入-1的元素pop出去
        }
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(hashmap[nums1[i]]); //直接從hashmap中獲取答案
        }
        return ans;
    }
};