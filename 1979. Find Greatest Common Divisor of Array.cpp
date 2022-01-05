class Solution {
public:
    //找最大公因數
    //使用輾轉相除法
    int gcd(int a,int b){
        if((a%b)==0) return b;
        else return gcd(b,a%b);
    }
    
    //主程式
    int findGCD(vector<int>& nums) {
        //排序輸入的數字
        sort(nums.begin(),nums.end());
        int max,min;
        //最小的數字在最前面
        min=nums[0];
        //最大的數字在最後面
        max=nums[nums.size()-1];
        //回傳最小和最大數字的最大公因數
        return gcd(max,min);
    }
};
