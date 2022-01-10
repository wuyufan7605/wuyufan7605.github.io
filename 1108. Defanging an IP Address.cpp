class Solution {
public:
    string defangIPaddr(string address) {
        //建一個叫做output的字串
        string output="";
        
        for(int i=0;i<address.length();i++){
            //如果遇到 . 就在output中加入[.]
            if(address[i]=='.'){
                output+="[.]";
            }
            //如果遇到其他的,就直接加到output
            else{
                output+=address[i];
            }
        }
        //回傳output
        return output;
    }
};