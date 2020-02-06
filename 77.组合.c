/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (71.78%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    32.3K
 * Total Submissions: 44.6K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
#include <stddef.h>
#include <stdint.h>

void backtrace(int first, int n, int k, int *stack, int size, int **returnArray, int *returnSize, int **returnColumnSizes)
{
    int i;

    if (k == size) {
        returnArray[*returnSize] = (int*)malloc(sizeof(int*) * k);
        memcpy(returnArray[*returnSize], stack, sizeof(int) * k);
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (i = first; i < n + 1; i++) {
        stack[size++] = i;
        backtrace(i + 1, n, k, stack, size, returnArray, returnSize, returnColumnSizes);
        size--;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int *returnArray;
    int allocSize = 100000;
    int *stack;
    int size = 0;

    *returnSize = 0;
    if (n < k) {
        return NULL;
    }
    stack = (int*)malloc(sizeof(int) * k);
    returnArray = (int**)malloc(sizeof(int*) * allocSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSize);
    backtrace(1, n, k, stack, size, returnArray, returnSize, returnColumnSizes);
    return returnArray;
}


// @lc code=end

