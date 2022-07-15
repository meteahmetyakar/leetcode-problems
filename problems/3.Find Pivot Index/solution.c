int pivotIndex(int* nums, int numsSize){
    int leftSum = 0, rightSum = 0, totalSum = 0;
    
    for(int i=0; i<numsSize; i++)
        totalSum += nums[i];
    
    for(int i=0; i<numsSize; i++)
    {        
        if(i>0)
            leftSum += nums[i-1];
        
        rightSum = totalSum-nums[i]-leftSum;
        
        if(leftSum == rightSum)
            return i;
            
    }
    
    return -1;   
}