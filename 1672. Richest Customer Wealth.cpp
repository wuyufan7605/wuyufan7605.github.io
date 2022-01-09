class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        //一開始最大weaith設0
        int maxwealth=0;
        //個人wealth也設0
        int customerWealth=0;

        for(int i=0;i<accounts.size();i++){
            //每次換人重新算時,要歸零,否則會一直累加
            customerWealth=0;
            //算個人wealth總和
            for(int j=0;j<accounts[i].size();j++){
                customerWealth+=accounts[i][j];
                
            }
            //所有人看誰最有錢
            if(customerWealth>maxwealth){
               maxwealth= customerWealth;
            }
        }
        //回傳最有錢的總財產
        return maxwealth;
    }
};