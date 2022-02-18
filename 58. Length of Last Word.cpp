class Solution {
public:
    int lengthOfLastWord(string s) {
        int right=s.size()-1;
        int res=0;
        //最後的字為空的話,往左檢查
        while(right>=0 && s[right]==' ') right--;
        //數最後的字有幾個字母
        while(right>=0&&s[right]!=' '){
            right--;
            res++;
        }
        return res;
    }
};