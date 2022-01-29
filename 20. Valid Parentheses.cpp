class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        int len=s.length();
        
        for(int i=0;i<len;i++){
            //如果出現左半邊,就push進stack k
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                k.push(s[i]);
            //如果出現右半邊
            else if(s[i]==')'|| s[i]==']'||s[i]=='}'){
                //但沒有左半邊,表示invaild
                if(k.empty())
                    return false;
                //判斷是否有出現對應的左半邊
                else if(s[i]==')'&& k.top()!='(')
                    return false;
                else if(s[i]==']'&& k.top()!='[')
                    return false;
                else if(s[i]=='}'&& k.top()!='{')
                    return false;
                //有對應的左半邊的話,就把左半邊pop出去
                else
                    k.pop();
            }
        }
        //最後檢查是否stack為空
        if(k.empty())
            return true;
        //不為空表示invaild
        else
            return false;
    }
};