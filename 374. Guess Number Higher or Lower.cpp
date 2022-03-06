/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //設定左右邊界
        int l=1;
        int r=n;

        while(l<=r){
            //中間值
            int mid=l+(r-l)/2;
            //二分搜尋
            if(guess(mid)==0) return mid;
            else if(guess(mid)>0){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
};