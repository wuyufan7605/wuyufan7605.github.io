class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        int n=num.size(),newSize=n-k;
        //歷遍num的每一位數字
        for(char c:num){
            //如果k>0,res不為空,res的最後一位>c
            while(k && res.size() && res.back()>c){
                //把最後一位pop出來
                res.pop_back();
                //k減一(因為已經去掉一個數字了)
                k--;
            }
            //把沒被去掉的c,push進res
            res.push_back(c);
        }
        //重新調整res的大小
        res.resize(newSize);
        //如果0在前面,就消除0(比如:0200)
        while(!res.empty() && res[0]=='0') res.erase(res.begin());
        //如果res為空,就回傳"0",不為空即回傳res
        return res.empty() ? "0" : res;
    }
};