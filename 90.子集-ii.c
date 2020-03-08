/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (57.97%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 37.1K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int partion(int *nums, int left, int right)
{
    int x = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= x) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= x) {
            left++;
        }
        nums[right] = nums[left]; 
    }
    nums[left] = x;
    return left;
}

void quicksort(int *nums, int left, int right)
{
    if (left < right) {
        int mid = partion(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    } 
}

void backtrace(int *nums, int numsSize, int **returnArray, int *returnSize, \
    int **returnColumnSizes, int *tmp, int pos, int size)
{
    int i;

    if (size > 0) {
        returnArray[*returnSize] = (int*)malloc(sizeof(int) * size);
        memcpy(returnArray[*returnSize], tmp, sizeof(int) * size);
    }
    (*returnColumnSizes)[*returnSize] = size;
    (*returnSize)++;
    for (i = pos; i < numsSize; i++) { 
        if (i > pos && nums[i - 1] == nums[i]) {
            continue;
        }
        tmp[size++] = nums[i];
        backtrace(nums, numsSize, returnArray, returnSize, returnColumnSizes, tmp, i + 1, size);
        size--;
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    const int allocSize = 10000;
    int **returnArray;
    int *tmp;
    int tmpsize;

    *returnSize = 0;
    returnArray = (int**)malloc(sizeof(int*) * allocSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSize);
    quicksort(nums, 0, numsSize - 1);
    tmp = (int*)malloc(sizeof(int) * allocSize);
    tmpsize = 0; 
    backtrace(nums, numsSize, returnArray, returnSize, returnColumnSizes, tmp, 0, tmpsize);
    return returnArray;
}


// @lc code=end

