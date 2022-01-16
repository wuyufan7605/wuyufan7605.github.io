class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //n為digits的長度
        int n=digits.size();
        
        //對每個digits的數字
        for(int i=n-1;i>=0;i--){
            //如果是9,因為進位,所以改成0
            if(digits[i]==9){
                digits[i]=0;
            }else{
                //其他的直接加1
                digits[i]++;
                //並回傳
                return digits;
            }
        }
        //如果是:999這種情況
        //就把最前面改成1
        digits[0]=1;
        //並在最後面補一個0
        digits.push_back(0);
        //最後回傳
        return digits;
    }
};