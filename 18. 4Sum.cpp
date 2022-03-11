class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //初始化並排序
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        //跑回圈
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int left=j+1;
                int right=nums.size()-1;
                int temp_target=target-nums[i]-nums[j];
                
                while(left<right){
                    int sum=nums[left]+nums[right];
                    
                    if(sum==temp_target){
                        vector<int>Results={nums[i],nums[j],nums[left],nums[right]};
                        
                        if(find(result.begin(),result.end(),Results)==result.end()){
                            result.push_back(Results);
                        }
                        left++;
                        right--;
                    }
                    else if(sum<temp_target){
                        left++;
                    }
                    else if(sum>temp_target){
                        right--;
                    }
                } 
            }
        }
        return result;
    }
};