/*18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/* set num in order */
int numcmp(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int i = 0, j = 0, k = 0, l = 0;
    int ret = 0;
    int mid = 0;
    int arraysize = 0;
    int **finalarray = (int **)malloc(sizeof(int *) * 1000);
    
    *returnSize = 0;
        
    if (nums == NULL || numsSize < 4){
        return 0;
    }
    
    //finalarray = (int **)malloc(sizeof(int *) * 1000); 
    
    qsort(nums, numsSize, sizeof(int), numcmp);
    /*for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }*/
    
    printf("\n");
    
    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        for ( j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            for ( k = j + 1; k < numsSize - 1; k++) {
                if (k > j + 1 && nums[k] == nums[k - 1]) {
                    continue;
                }
                
                for ( l = k + 1; l < numsSize; l++) {
                
                    if (l > k + 1 && nums[l] == nums[l - 1]) {
                        continue;
                    }
                    
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        /*printf("nums[%u]=%d, nums[%u]=%d, nums[%u]=%d, nums[%u]=%d \n",
                               i, nums[i], j, nums[j], k, nums[k], l, nums[l]);
                        printf("arraysize = %u \n", arraysize);*/
                        finalarray[arraysize] = (int *)malloc(sizeof(int) * 4);
                        finalarray[arraysize][0] = nums[i];
                        finalarray[arraysize][1] = nums[j];
                        finalarray[arraysize][2] = nums[k];
                        finalarray[arraysize][3] = nums[l];
                        /*printf("finalarray[0]=%d, finalarray[1]=%d, finalarray[2]=%d, finalarray[3]=%d \n",
                               finalarray[arraysize][0], finalarray[arraysize][1], finalarray[arraysize][2],
                               finalarray[arraysize][3]);*/
                        arraysize += 1;
                    }
                }
            }
        }
    }
    
    *returnSize = arraysize;
    *returnColumnSizes = (int *)malloc(sizeof(int *) * (*returnSize)); 
    for (i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = 4;
    }
    

    /*for (i = 0; i < arraysize; i++) {
        printf("", i);
        for (j = 0; j < 4; j++) {
           printf("%d ", finalarray[i][j]); 
        }
        printf("\n");
    }*/

    
    return finalarray;
        

}