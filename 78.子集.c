/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.67%)
 * Likes:    459
 * Dislikes: 0
 * Total Accepted:    57.8K
 * Total Submissions: 75.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
#include <stddef.h>
#include <stdint.h>

void backtrace(int *nums, int first, int numsSize, int *stack, int size, int **returnArray, int *returnSize, int **returnColumnSizes)
{
    int i;

    if (size > 0 && size <= numsSize) {
        returnArray[*returnSize] = (int*)malloc(sizeof(int*) * size);
        memcpy(returnArray[*returnSize], stack, sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
        //return;
    }

    for (i = first; i < numsSize; i++) {
        stack[size++] = nums[i];
        backtrace(nums, i + 1, numsSize, stack, size, returnArray, returnSize, returnColumnSizes);
        size--;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *returnArray;
    int allocSize = 100000;
    int *stack;
    int size = 0;

    *returnSize = 0;
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }
    stack = (int*)malloc(sizeof(int) * numsSize);
    returnArray = (int**)malloc(sizeof(int*) * allocSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSize);

    (*returnColumnSizes)[*returnSize] = 0;
    (*returnSize)++;
    backtrace(nums, 0, numsSize, stack, size, returnArray, returnSize, returnColumnSizes);
    
    return returnArray;
}


// @lc code=end

