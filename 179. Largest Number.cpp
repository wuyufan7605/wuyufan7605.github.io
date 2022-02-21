class Solution {
public:
    //倆倆數字組合比較
    static bool cmp(int a,int b){
        //將數字a跟數字b轉成字符串,回傳比較大的組合
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string largestNumber(vector<int>& nums) {
        string res;
        //將整組字串依上面函式排序後
        sort(nums.begin(),nums.end(),cmp);
        //將每個數字轉為字串再串起來
        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
        }
        //如果res為空,回傳"0",否則回傳res
        return res[0]=='0' ? "0" : res;
    }
};