/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.09%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    72K
 * Total Submissions: 97.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static inline void swap(int *nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void backtrace(int *nums, int start, int end, int *returnSize, int **returnArray, int **returnColumnSizes)
{
    int i;

    if (start == end + 1) {
        returnArray[*returnSize] = (int*)malloc(sizeof(int) * (end + 1));
        memcpy(returnArray[*returnSize], nums, sizeof(int) * (end + 1));
        (*returnColumnSizes)[*returnSize] = end + 1;
        (*returnSize)++;
        return;
    }
    for (i = start; i <= end; i++) {
        swap(nums, i, start);
        backtrace(nums, start + 1, end, returnSize, returnArray, returnColumnSizes);
        swap(nums, start, i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **returnArray;
    int allocSize = 10000;

    *returnSize = 0;
    if (nums == 0 || numsSize == 0) {
        return NULL;
    }
    returnArray = (int**)malloc(sizeof(int*) * allocSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSize);
    backtrace(nums, 0, numsSize - 1, returnSize, returnArray, returnColumnSizes);
    return returnArray;
}


// @lc code=end

