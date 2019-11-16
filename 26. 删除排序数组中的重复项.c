/*26. 删除排序数组中的重复项
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。

示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int removeDuplicates(int* nums, int numsSize){
    int *pstFirst = 0;
    int i = 0;
    int totalcnt = 0;

    if (nums == 0 || numsSize == 0) {
        return 0;
    }

    /*for (i = 0; i < numsSize; i++) {
        printf("nums[%u]=%u ", i, nums[i]);
    }
    printf("\n");*/

    pstFirst = &nums[0];
    totalcnt = 1;
    for (i = 1; i < numsSize; i++) {
        //printf("111 nums[%u]=%u, pstFirst=%u, pstFirst=%p\n", i, nums[i], *pstFirst, pstFirst);
        if (*pstFirst == nums[i]) {
           //printf("nums[%u]=%u, pstFirst=%u\n", i, nums[i], *pstFirst);
            continue;
        } else {
            *(++pstFirst) = nums[i];
            totalcnt++;
            //printf("222 nums[%u]=%u, pstFirst=%u, pstFirst=%p\n", i, nums[i], *pstFirst, pstFirst);
        }
    }

    /*printf("totalcnt=%u \n", totalcnt);
    for (i = 0; i < totalcnt; i++) {
        printf("nums[%u]=%u ", i, nums[i]);
    }*/
    return totalcnt;
    
}