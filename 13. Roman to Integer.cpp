class Solution {
public:
    int romanToInt(string s) {
        //建立map:將與字母對應的數字放在一起
        map<char,int>m{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        //p表示上一個字的index
        int p=0;
        //ans為數字的值(即最終要求的)
        int ans=0;
        for(char c:s){
            //把所有的值都先加起來
            ans+=m[c];
            //如果前面的值比較小,就減2*前面的值
            if(m[c]>m[p]){
                ans=ans-2*m[p];
            }
            //往下一個移動
            //所以現在的值變成前一個的值
            p=c;
        }
        return ans;
    }
};