class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0,m=haystack.size(),n=needle.size();
        size_t pos=haystack.find(needle);
        //如果needle為空
        if(needle.empty()) return 0;
        //如果沒找到needle
        if(pos<0) return -1;
        //如果有找到needle
        return pos;
    }
};