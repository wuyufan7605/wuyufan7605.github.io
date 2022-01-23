class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //排序每個點距離原點之平方
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
        });
        //回傳第k個小的距離之點座標
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};