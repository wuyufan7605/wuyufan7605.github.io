class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //初始化,將要回傳的答案先設成空
        string ans="";
        //for循環歷遍字典每個字串
        for(string member: dictionary){
            int i=0,j=0;
            //如果當前的答案的長度<歷遍到的字典中的字串長度 或 兩者長度相同時,選擇index較小的
            if(ans.size()<member.size()|| (ans.size()==member.size())&&(ans.compare(member)>0)){
                //s及dictionary不超出字符串長度的情況下,循環判斷
                while(i<s.size() && j<member.size()){
                    //如果兩個字符串現在元素相同,member指針向後移一格
                    if(s[i]==member[j]){
                        j++;
                    }
                    //不同則s指針向後移
                    i++;
                }
            }
            //若指針j最後的長度與member長度相同,滿足了題意,即member為s的子字串,答案即為member
            if(j==member.size()){
                ans=member;
            }
        }
        return ans;
    }
};