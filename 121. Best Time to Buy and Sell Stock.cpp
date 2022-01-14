class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy為最低買入價格,先設成第一個數
        int buy=prices[0];
        //profit為利潤,先設成0
        int profit=0;
        //如果沒東西或只有一個數,就回傳0
        if(prices.empty()||prices.size()==1){
            return 0;
        }
        //如果後來的數比最低買入還高,就算一下profit,然後透過迴圈取最大值
        //如果之後的數有比最低買進數還小的,就透過迴圈,取出最小的
        for(int i=1;i<prices.size();i++){
            if(prices[i]>buy){
                profit=max(profit,prices[i]-buy);
            }else{
                buy=min(buy,prices[i]);
            }
        }
        //回傳利潤最大的
        return profit;
    }
};