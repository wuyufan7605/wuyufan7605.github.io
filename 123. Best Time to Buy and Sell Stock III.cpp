class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice1=INT_MAX;
        int profit1=0;
        int minPrice2=INT_MAX;
        int profit2=0;
        for(int i=0;i<prices.size();i++){
            //第一次交易的minPrice跟profit
            minPrice1=min(minPrice1,prices[i]);
            profit1=max(profit1,prices[i]-minPrice1);
            //第二次交易:要從口袋掏出的錢,和利潤
            minPrice2=min(minPrice2,prices[i]-profit1);
            profit2=max(profit2,prices[i]-minPrice2);
        }
        //回傳最終利潤
        return profit2;
    }
};