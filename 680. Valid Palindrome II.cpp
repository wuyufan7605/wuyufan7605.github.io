class Solution {
public:
    //用來確認字串是否回文
    bool checkPalindrome(string &s,int low,int high){
        //確認前後雙指針是否不同
        for(int i=low,j=high;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int low=0;
        int high=s.size()-1;
        while(low<high){
            //當前前後指針指向的兩個字符相同,繼續移動指針
            if(s[low]==s[high]){
                low++;
                high--;
            }
            //不同時,跳過一個字符來確認是否回文
            else{
                return checkPalindrome(s,low+1,high)||checkPalindrome(s,low,high-1);
            }
        }
        return true;
    }
};