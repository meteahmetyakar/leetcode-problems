int* countBits(int n, int* returnSize){

    n++;
    int* tempArray = (int*)calloc(n, sizeof(int));
    
    *returnSize = n;
    
    int targetPower=1, counter = 0;
    for(int i=1; i<n; i++, counter++)
    {
        if(counter == targetPower)
        {
            counter = 0;
            targetPower *= 2;
        }
        tempArray[i] = tempArray[counter] + 1;
    }   
    
    return tempArray;
}