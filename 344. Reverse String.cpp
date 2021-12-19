class Solution {
public:
    void reverseString(vector<char>& s) {
        #s為題目給的
        #將字母最前跟最後交換
        #然後不斷望內層移動,再倆倆交換
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
    }
};