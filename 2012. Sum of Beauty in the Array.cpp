class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        //prefix表index 0~i-1之最大值
        //suffix表index i+1~n-1之最小值
        vector<int>prefix(n),suffix(n);
        int ans=0;
        //由於prefix的最開始 和suffix的最後面沒有存到,所以給個值
        prefix[0]=0;
        suffix[n-1]=100001;
        //存prefix
        for(int i=1;i<n;++i){
            prefix[i]=max(prefix[i-1],nums[i-1]);
        }
        //存suffix
        for(int i=n-2;i>=0;--i){
            suffix[i]=min(suffix[i+1],nums[i+1]);
        }
        //依照題目規定,比左邊全部大也比右邊全部小:加二
        //如果只有比左邊一個數大,比右邊一個數小:加一
        for(int i=1;i<n-1;++i){
            if(nums[i]>prefix[i]&&nums[i]<suffix[i]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1]){
                ans+=1;
            }
        }
        //回傳ans
        return ans;
    }
};