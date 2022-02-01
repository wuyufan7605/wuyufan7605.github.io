class Solution {
public:
    bool isPalindrome(int x) {
        //把整數轉成字串
        string s=to_string(x),t=s;
        //反轉順序
        reverse(t.begin(),t.end());
        //比較反轉前後是否相同
        return s==t? true:false;
    }
};