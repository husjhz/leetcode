/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (58.82%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 61.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int partion(int *nums, int left, int right)
{
    int target = nums[left];

    while (left < right) {
        while (left < right && nums[right] >= target) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= target) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = target;
    return left;
}

static void quicksort(int *nums, int left, int right)
{
    if (left < right) {
        int mid = partion(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    }
}

struct stack {
    int *array;
    int capacity;
    int size;
};

static struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack*)malloc(sizeof(struct stack));
    s->array = (int*)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

static int push(struct stack *s, int x)
{
    if (s->size == s->capacity) {
        return -1;
    }
    s->array[s->size++] = x;
    return s->size;
}

static int pop(struct stack *s, int *px)
{
    if (s->size == 0) {
        return -1;
    }
    *px = s->array[--s->size];
    return s->size;
}

int isDuplicate(struct stack *s, int *returnSize, int **returnArray, int **returnColumnSizes)
{
    int i, j;
    int count;

    quicksort(s->array, 0, s->size - 1);
    if (*returnSize == 0) {
        return 0;
    }
    for (i = 0; i < *returnSize; i++) {
        if (s->size != (*returnColumnSizes)[i]) {
            continue;
        }
        count = 0;
        for (j = 0; j < s->size; j++) {
            if (s->array[j] != returnArray[i][j]) {
                break;
            }
            count++;
        }
        if (count == s->size) {
            return 1;
        }
    }
    return 0;
}

void dfs(int *candidates, int start, int end, int target, struct stack *s,
    int *returnSize, int **returnArray, int **returnColumnSizes, int *usedMaps)
{
    int i;
    int data;

    if (target == 0) {
        if (isDuplicate(s, returnSize, returnArray, returnColumnSizes)) {
            return;
        }
        returnArray[*returnSize] = (int*)malloc(sizeof(int) * s->size);
        memcpy(returnArray[*returnSize], s->array, sizeof(int) * s->size);
        (*returnColumnSizes)[*returnSize] = s->size;
        (*returnSize)++;
        return;
    }
    for (i = start; i <= end && target - candidates[i] >= 0; i++) {
        if (usedMaps[i] == 1) {
            continue;
        }
        push(s, candidates[i]);
        usedMaps[i] = 1;
        dfs(candidates, i, end, target - candidates[i], s, returnSize, returnArray, returnColumnSizes, usedMaps);
        pop(s, &data);
        usedMaps[i] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **returnArray;
    int allocSizes = 1000;
    struct stack *stack;
    int i;
    int *usedMaps;

    *returnSize = 0;
    if (candidates == NULL || candidatesSize == 0) {
        return NULL;
    }
    quicksort(candidates, 0, candidatesSize - 1);
    returnArray = (int**)malloc(sizeof(int*) * allocSizes);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSizes);
    stack = create(allocSizes);
    usedMaps = (int*)malloc(sizeof(int) * candidatesSize);
    dfs(candidates, 0, candidatesSize - 1, target, stack, returnSize, returnArray, returnColumnSizes, usedMaps);

    return returnArray;
}

// @lc code=end

