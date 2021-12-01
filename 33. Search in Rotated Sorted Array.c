

int search(int* nums, int numsSize, int target){
   
    int start=0;
    int end=numsSize;
    
   
    while(true){
        if(start==end) return -1;
         int mid=(start+end)/2;
    
    if(nums[mid]==target){
        return mid;
    }
        if(nums[mid]<target){
        //B
        if(nums[0]>nums[mid]){
            if(nums[0]>target){
                //FindRight();
                start=mid+1;
            }else{
                //FindLeft
                end=mid;
            }
        }else{
            //A
            //FindRight
            start=mid+1;
        }
    }
    if(nums[mid]>target){
        if(nums[0]>nums[mid]){
            //B
            //FindLeft
              end=mid;
        }else{
            //A
            if(nums[0]>target){ 
               //FindRight
                start=mid+1;
            }else{
                //FindLeft
                 end=mid;
            }
        }
    }
    
    

    }
    

    return -1;
}