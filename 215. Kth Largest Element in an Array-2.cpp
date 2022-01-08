class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int>q(nums.begin(),nums.end());
        //把第k大的數字之前的數字(比第k個數字大的數字)都pop掉
        for(int i=1;i<k;i++){
            q.pop();
        }
        //回傳最上面的那個(就是第k個大的)
        return q.top();
    }
};