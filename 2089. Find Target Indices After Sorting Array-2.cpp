public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //cnt表示目標出現在nums中幾次
        int cnt=0;
        //rank表示小於目標的數字出現次數的總和
        int rank=0;
        //建一個vector叫做ans
        vector<int>ans;
        //對所有在nums中的整數
        for(int n:nums){
            //如果出現目標,cnt就+1
            cnt+= n==target;
            //如果出現小於目標的數,rank就加一
            rank+= n<target;
        }
        //目標出現幾次,就push幾次(表示最後會有幾個index)
        //rank為比目標小數次出現的次數
        //又index從0開始
        //所以++在後面
        while(cnt--) ans.push_back(rank++);
        //回傳答案
        return ans;
    }
};