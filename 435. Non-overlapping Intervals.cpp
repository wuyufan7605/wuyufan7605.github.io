class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        //從第一個區間的結尾開始
        int left=intervals[0][1];
        for(int i=1;i<n;i++){
            //如果有重疊,留下尾巴數字小的區間
            if(intervals[i][0]<left){
                count++;
                left=min(left,intervals[i][1]);
            }
            //不重複則指針向後移
            else left=intervals[i][1];
        }
        return count;
    }
};