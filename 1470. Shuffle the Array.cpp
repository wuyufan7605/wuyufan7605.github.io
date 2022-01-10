class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>output;
        //先把xi放到output
        //再放yi
        //利用迴圈部段重複,直到全部x跟y都放進去
        for(int i=0;i<n;i++){
            output.push_back(nums[i]);
            output.push_back(nums[i+n]);
        }
        //回傳output
        return output;
    }
};