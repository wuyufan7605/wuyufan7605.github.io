class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> toSort;
        for(int i=0;i<points.size();i++){
            //把每個點的距離平方push進toSort
            toSort.emplace_back(points[i][0]*points[i][0]+points[i][1]*points[i][1],i);
        }
        //進行排序
        sort(toSort.begin(),toSort.end());
        
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            //把要的push進ans
            ans.push_back(points[toSort[i].second]);
        }
        return ans;
    }
};