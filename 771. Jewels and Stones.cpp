class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        //使用unordered_set(做hash set)
        unordered_set<char> J_set(jewels.begin(),jewels.end());
        int count=0;

        for(char s:stones){
            //對每個stones裡的string,如果有出現在jewels中,就count++
            if(J_set.count(s)) count++;
        }
        //回傳出現次數
        return count;
    }
};