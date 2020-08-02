/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (54.90%)
 * Likes:    628
 * Dislikes: 0
 * Total Accepted:    146.1K
 * Total Submissions: 265.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */

// @lc code=start



typedef struct {
    int data[10000];
    int min[10000];
    int data_top;
    int min_top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *s;

    s = (MinStack *)malloc(sizeof(MinStack));
    s->data_top = -1;
    s->min_top = -1;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->min_top < 0 && obj->data_top < 0) {
        obj->min[++obj->min_top] = x;
    }
    else if (obj->min_top >= 0 && x <= obj->min[obj->min_top]) {
        obj->min[++obj->min_top] = x;
    }
    obj->data[++obj->data_top] = x;
}

void minStackPop(MinStack* obj) {
    if (obj->min_top >= 0 && obj->min[obj->min_top] == obj->data[obj->data_top]) {
        obj->min_top--;
    }
    obj->data_top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->data_top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->min_top >= 0)
        return obj->min[obj->min_top];
    else
        return obj->data[obj->data_top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end
