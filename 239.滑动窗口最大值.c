/*
 * @lc app=leetcode.cn id=239 lang=c
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (44.71%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    36.9K
 * Total Submissions: 81.8K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

struct dqueue {
    int *array;
    int front;
    int rear;
    int capacity;
    int size;
};

struct dqueue *create(int capacity)
{
    struct dqueue *s;

    s = (struct dqueue *)malloc(sizeof(struct dqueue));
    s->array = (int *)malloc(sizeof(int) * capacity);
    s->front = 0;
    s->rear = 0;
    s->capacity = capacity;
    s->size = 0;
    return s;
}

int empty(struct dqueue *s)
{
    return s->size == 0;
}

void push(struct dqueue *s, int x)
{
    s->array[s->front] = x;
    s->front = (s->front + 1) % s->capacity;
    s->size++;
}

int peek(struct dqueue *s)
{
    return s->array[s->rear];
}

int peek_front(struct dqueue *s)
{
    int front;

    front = (s->front - 1) % s->capacity;
    return s->array[front];   
}

int pop(struct dqueue *s)
{
    int x;

    x = s->array[s->rear];
    s->rear = (s->rear + 1) % s->capacity;
    s->size--;
    return x;
}

int pop_front(struct dqueue *s)
{
    s->front = (s->front - 1) % s->capacity;
    s->size--;
    return s->array[s->front];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    struct dqueue *s;
    int *returnArray;
    int i;

    *returnSize = 0; 
    returnArray = (int *)malloc(sizeof(int) * numsSize);
    s = create(numsSize + 1);
    for (i = 0; i < numsSize; i++) {
        if (!empty(s) && peek(s) == i - k) {
            pop(s);
        }
        while (!empty(s) && nums[i] > nums[peek_front(s)]) {
            pop_front(s);
        }
        push(s, i);
        if (i - k + 1 >= 0) {
            returnArray[*returnSize] = nums[peek(s)];
            (*returnSize)++;
        }
    }
    return returnArray;
}


// @lc code=end

