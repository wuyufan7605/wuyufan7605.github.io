class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1;
        while(true){
            int pos=partition(nums,left,right);
            //剛好為k-1,直接回傳
            if(pos==k-1) return nums[pos];
            //如果是比index pos大的數字,就往左邊繼續partition
            if(pos>k-1) right=pos-1;
            //如果是比index pos小的數字,就往右邊繼續partition
            else left=pos+1; 
        }
    }
    int partition(vector<int>& nums,int left,int right){
        //設一個pivot(中樞點),還有l跟r
       int pivot=nums[left],l=left+1,r=right;
       //l<=r,才不會重複比
        while(l<=r){
            //把大的數字跟小的數字交換(大的在左邊,小的在右邊)
            if(nums[l]<pivot&&nums[r]>pivot){
                swap(nums[l++],nums[r--]);
            }
            //如果本來左邊的數字就比pivot大,就看右邊下一個數字
            if(nums[l]>=pivot) ++l;
            //如果本來右邊的數字就比pivot小,就看左邊下一個數字
            if(nums[r]<=pivot) --r;
        }
        //最後,把比pivot大的其中一個數字(也就是r index的數字)
        //跟pivot交換
        swap(nums[left],nums[r]);
        return r;
    }
    
    
};