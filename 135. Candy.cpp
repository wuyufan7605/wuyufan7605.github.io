class Solution {
public:
    int candy(vector<int>& ratings) {
        int child_num=ratings.size();
        //小孩小於2可以直接回傳
        if(child_num<2){
            return child_num;
        }
        //建一個vector叫candys,表示每個孩子拿到的糖果數
        vector<int> candys(child_num,1);
        //由左到右
        for(int i=1;i<child_num;i++){
            //如果右邊的數字比較大
            if(ratings[i-1]<ratings[i]){
                //右邊分的糖果要比左邊多一
                candys[i]=candys[i-1]+1;
            }
        }
        //由右到左
        for(int i=child_num-1;i>0;i--){
            //如果左邊的數字比較大,左邊分的糖果要比右邊多一
            if(ratings[i-1]>ratings[i]){
                //比較:由左到右 由右到左 取最大的那個
                candys[i-1]=max(candys[i-1],candys[i]+1);
            }
        }
        //把所有小朋友拿的糖果加總並回傳
        return accumulate(candys.begin(),candys.end(),0);
    }
};