class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //建一個vector叫refund
        vector<int> refund;
        //先把minCost設成0
        int minCost=0;
        //N為一半長度,因為題目要求一半人去A城市,一半去B城市
        int N=costs.size()/2;
        for(vector<int> cost:costs){
            //先把所有去A城市的cost加起來
            minCost +=cost[0];
            //計算每個人:B城市的cost-A城市的cost,並push進refund
            refund.push_back(cost[1]-cost[0]);
        }
        //refund由小排到大
        sort(refund.begin(),refund.end());
        
        for(int i=0;i<N;i++){
            //加上一半的refund
            minCost+=refund[i];
        }
        //回傳最小的cost
        return minCost;
    }
};