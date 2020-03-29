/*
 * @lc app=leetcode.cn id=503 lang=c
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (53.35%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
 * 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 注意: 输入数组的长度不会超过 10000。
 * 
 */

// @lc code=start
#include <stddef.h>

struct stack {
    int *array;
    int capacity;
    int size;
};

struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack *)malloc(sizeof(struct stack));
    s->array = (int *)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

int empty(struct stack *s)
{
    return s->size == 0;
}

void push(struct stack *s, int x)
{
    s->array[s->size++] = x;
}

int top(struct stack *s)
{
    return s->array[s->size - 1];
}

int pop(struct stack *s)
{
    return s->array[--s->size];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    struct stack *s;
    int *returnArray;
    int i;
    int x;

    *returnSize = numsSize;
    if (numsSize < 1) {
        return NULL;
    }
    returnArray = (int *)malloc(sizeof(int) * numsSize);
    if (numsSize == 1) {
        returnArray[0] = -1;
        return returnArray;
    }
    s = create(2 * numsSize);
    while (i < numsSize) {
        while (!empty(s)) {
            if (nums[i] <= nums[top(s)]) {
                break;
            }
            x = pop(s);
            returnArray[x] = nums[i];
        }
        push(s, i++);
    }
    while (!empty(s)) {
        x = pop(s);
        for (i = 0; i < numsSize; i++) {
            if (nums[i] > nums[x]) {
                returnArray[x] = nums[i];
                break;
            }
        }
        if (i == numsSize) {
            returnArray[x] = -1;
        }
    }
    return returnArray;
}


// @lc code=end

