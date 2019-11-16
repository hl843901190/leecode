int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int i = 0, j = 0;
    int *res = 0;
    
    if (nums == 0 || numsSize < 2) {
        *returnSize = 0;
        return 0;
    }
    
    res = (int *)malloc(sizeof(int) * 2);
    for (i = 0; i < 2; i++) {
        res[i] = 0;
    }
    
    for (i = 0; i < numsSize; i++) {
        for ( j = numsSize -1 ; j > i; j--) {

            //printf("nums[%u]=%d, nums[%u]=%d, target=%d", i, nums[i], j, nums[j], target);
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                break;
            }
        }
        
        //printf("res[0]=%d, res[1]=%d", res[0], res[1]);
        if (res[0] != 0 && res[1] != 0) {
            break;
        }
    }
    
    *returnSize = 2;
    
    return res;
}