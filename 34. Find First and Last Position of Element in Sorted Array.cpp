class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left1=0;
        int right=nums.size();
        
        //確保left1不會超過right
        while(left1<right){
            int mid=left1+(right-left1)/2;
            //target在左邊
            if(nums[mid]>=target){
                 right=mid;
            }
            //target在右邊
            else{
                left1=mid+1;
            }  
        }
        //沒有出現target,回傳-1
        if(left1==nums.size()||nums[left1]!=target){
                left1=-1;
                return {-1,-1};
        }
        
        //確認第二個(最後一個)target的位置
        int left2=0;
        right=nums.size();
        
        while(left2<right){
            int mid=left2+(right-left2)/2;
            //target在左邊
            if(nums[mid]>target)  right=mid;
            //target在右邊
            else                  left2=mid+1;
        }
        return {left1,left2-1};
    }
};