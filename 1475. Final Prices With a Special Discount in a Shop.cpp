class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        //使用雙層迴圈
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //如果後一個數字比較小,就把前面數字更新為:前面-後面
                //並退出迴圈
                if(prices[j]<=prices[i]){
                    prices[i]-=prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};