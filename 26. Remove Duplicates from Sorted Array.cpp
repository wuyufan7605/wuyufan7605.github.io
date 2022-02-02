class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int i=0;
        for(int i=0;i<nums.size();i++){
            //如果現在的數字跟前面的不同
           if(index==0||nums[i]!=nums[i-1]){
               //就改掉原本重複的數字
                nums[index]=nums[i];
                //往下一個數字繼續檢查
                index++;
            } 
        }   
        return index;
    }
};