class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hash;
        //數每個字母出現的次數
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
        }
        //把第一個出現次數為1的字母印出
        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==1)
                return i;
        }
        return -1;
    }
};