class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //最後買進賣出的差
        int maxAns=0;
        //看哪個會比前一天大,就把差加起來
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                maxAns+=prices[i]-prices[i-1];
            }
        }
        //回傳差的總和
        return maxAns;
    }
};