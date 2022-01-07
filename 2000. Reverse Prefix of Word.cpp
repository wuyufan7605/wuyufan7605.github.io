class Solution {
public:
    string reversePrefix(string word, char ch) {
        //l為word的長度
        int l=word.length();
        
        for(int i=0;i<l;i++){
            //如果遇到ch
            if(word[i]==ch){
                //就把第一個到ch反轉
                //使用C++ reverse函数
                reverse(word.begin(),word.begin()+i+1);
                break;
            }
        }
        //回傳
        return word; 
    }
};