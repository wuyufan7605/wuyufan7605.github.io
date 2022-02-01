class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //字串長度
        int n=nums.size();

        for(int i=0;i<n;){
            //如果跟目標相同數字
            if(nums[i]==val){
                //刪去相同的數字
                nums.erase(nums.begin()+i);
                //總數字個數減一
                n--;
            }else{
                //跟目標數字不同時,換比下一個數字
                i++;
            }
        }
        //回傳刪去後的總數字個數
        return n;
    }
};