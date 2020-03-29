/*
 * @lc app=leetcode.cn id=739 lang=c
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (59.33%)
 * Likes:    262
 * Dislikes: 0
 * Total Accepted:    36.8K
 * Total Submissions: 62K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
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
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    struct stack *s;
    int i;
    int *returnArray;
    int x;

    *returnSize = 0;
    if (TSize < 1) {
        return NULL;
    }
    returnArray = (int *)malloc(sizeof(int) * TSize);
    *returnSize = TSize;
    if (TSize == 1) {
        returnArray[0] = 0;
        return returnArray;
    }
    s = create(TSize + 1);
    push(s, 0);
    i = 1;
    while (!empty(s) && i < TSize) {
        if (T[i] <= T[top(s)]) {
            push(s, i++);
        }
        else {
            x = pop(s);
            returnArray[x] = i - x;
        }
        if (empty(s) && i < TSize) {
            push(s, i++);
        }
    }
    while (!empty(s)) {
        x = pop(s);
        returnArray[x] = 0;
    }
    return returnArray;
}


// @lc code=end

