class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int searchIndex=0;
        int count=0;
        //看題目要找type或color或name
        if(ruleKey=="color"){
            searchIndex=1;
        }else if(ruleKey=="name"){
            searchIndex=2;
        }
        //一個個找題目要的
        for(int i=0;i<items.size();i++){
            if(items[i][searchIndex]==ruleValue){
                count++;
            }
        }
        //回傳符合的個數
        return count;
    }
};