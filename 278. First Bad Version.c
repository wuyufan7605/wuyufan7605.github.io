// The API isBadVersion is defined for you.
//指leetcode已經定義好isBadVersion函式
// bool isBadVersion(int version);

//先自己定義一個二元搜尋的函式
//因為怕整數做運算時會溢位,所以用long long
long long binarySearch(long long first,long long last){
    //因為怕溢位,所以先算第一個數字跟最後一個數字的距離
    //因為要求中間值,所以把距離除以二,再加上第一個數
    long long mid=first+(last-first)/2;
    //如果中間值為BAD,中間值前一個數為GOOD,則中間值即為答案
    if(isBadVersion(mid)&&!isBadVersion(mid-1)){
        return mid;
    }
    //如果中間值不是BAD,即為GOOD
    //則往右邊找
    if(!isBadVersion(mid)){
        return binarySearch(mid+1,last);
    }
    //非上述幾種,則表示中間值為BAD,往左邊找
    return binarySearch(first,mid);
    
}
int firstBadVersion(int n) {
    //使用上述定義之函式
    //起點為1(題目規定),終點為n+1
    //因為我個人設定為:包括起點,不包括終點
    return binarySearch(1,(long long)n+1);
    
}