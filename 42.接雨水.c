/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.55%)
 * Likes:    815
 * Dislikes: 0
 * Total Accepted:    49.1K
 * Total Submissions: 102K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
struct stack {
    int *array;
    int capacity;
    int size;
    int top;
};

static struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack *)malloc(sizeof(struct stack));
    s->array = (int *)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size = 0;
    s->top = 0;
    return s;
}

static int push(struct stack *s, int x)
{
    if (s->size == s->capacity) {
        return -1;
    }
    s->array[s->size++] = x;
    s->top = x;
    return s->size;
}

static int pop(struct stack *s, int *px)
{
    if (s->size == 0) {
        return -1;
    }
    *px = s->array[--s->size];
    if (s->size > 0) {
        s->top = s->array[s->size - 1];
    }
    return s->size;
}

static inline MIN(int a, int b)
{
    return a < b ? a : b;
}

int trap(int* height, int heightSize){
    struct stack *stack;
    int i = 0;
    int area = 0;
    int top;
    int distance;
    int h;

    if (height == NULL || heightSize < 2) {
        return 0;
    }
    stack = create(heightSize);
    while (i < heightSize) {
        while (stack->size > 0 && height[i] > height[stack->top]) {
            pop(stack, &top);
            if (stack->size == 0) {
                break;
            }
            distance = i - stack->top - 1;
            h = MIN(height[i], height[stack->top]) - height[top];
            area += distance * h;
        }
        push(stack, i++);
    }
    return area;
}


// @lc code=end

