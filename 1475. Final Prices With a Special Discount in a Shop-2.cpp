class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //建立一個stack
        stack<int>s;
        for(int i=0;i<prices.size();i++){
            //只要stack不為空,且現在所在位置的price<=stack頂端的價錢的話
            while(!s.empty()&&prices[s.top()]>=prices[i]){
                //頂端減掉現在的price
                prices[s.top()]-=prices[i];
                //pop頂端的price
                s.pop();
            }
            //把現在的price的index存進stack中
            s.push(i);
        }
        return prices;
    }
};