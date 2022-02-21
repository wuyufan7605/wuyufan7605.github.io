class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //排序intervals
        sort(intervals.begin(),intervals.end());
        
        //初始化
        int ans=1;
        int startpoint=intervals[0][0];
        int endpoint=intervals[0][1];
        
        //比較
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]>endpoint){
                if(intervals[i][0]>startpoint){
                    ans++;
                }
                endpoint=intervals[i][1];
                startpoint=intervals[i][0];
            }
        }
        return ans;
    }
};