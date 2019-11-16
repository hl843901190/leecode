int numcmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **res = 0;
    int i = 0, j = 0, k = 0;
    int arraycnt = 0;
    int result = 0;
    
    *returnSize = 0;
    if(nums == 0 || numsSize < 3) {
        return 0;
    }
    
    res = (int **)malloc(sizeof(int *) * (numsSize + 1) * 10);
    
    qsort(nums, numsSize, sizeof(int), numcmp);
    /*for (i = 0; i < numsSize; i++) {
        printf("NUMS[%u] = %d, ", i, nums[i]);
    }
    printf("\n");*/
    
    
    for (i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        j = i + 1;
        k = numsSize - 1;
        //printf("i = %u, j=%u, k=%u\n", i, j, k);
        while (j < k) {
            //printf("nums[%u]=%d, nums[%u]=%d, nums[%u]=%d\n",i, nums[i], j, nums[j], k, nums[k]);
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            
            if (k < numsSize -1 && nums[k] == nums[k + 1]) {
                k--;
                continue;
            }
            
            result = nums[i] + nums[j] + nums[k];
            //printf("result=%d ", result);
            if (result > 0) {
                k--;
                continue;
            } else if (result < 0) {
                j++;
                continue;
            } else {
                //printf("arraycnt=%u, j=%u, k=%u\n", arraycnt, j, k);
                res[arraycnt] = (int *)malloc(sizeof(int) * 3);
                res[arraycnt][0] = nums[i];
                res[arraycnt][1] = nums[j];
                res[arraycnt][2] = nums[k];
                //printf("arraycnt=%u, res[0]=%d, res[1]=%d, res[2]=%d\n", arraycnt, res[arraycnt][0], res[arraycnt][1], res[arraycnt][2]);
                arraycnt++;
                j++;
            }
        }
    }

    //printf("arraycnt=%u", arraycnt);
    *returnSize = arraycnt;
    *returnColumnSizes = (int *)malloc(sizeof(int *) * (*returnSize)); 
    for (i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = 3;
    }

    
    return res;
}