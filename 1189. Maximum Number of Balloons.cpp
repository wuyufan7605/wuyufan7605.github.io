class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //建一個map
        unordered_map<char,int> mm;
        //統計每個字母出現的次數
        for(char i : text) mm[i]+=1;
        //回傳最小的次數
        return min(mm['b'],min(mm['a'],min(mm['l']/2,min(mm['o']/2,mm['n']))));
    }
};