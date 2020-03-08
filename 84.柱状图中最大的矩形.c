/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (37.79%)
 * Likes:    432
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 70K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
#include <stddef.h>

int largestRectangleArea(int* heights, int heightsSize){
    int *stack;
    int stackSize = 0;
    int i;
    int maxArea = 0;

    if (heights == NULL ||  heightsSize == 0) {
        return 0;
    }
    stack = (int*)malloc(sizeof(int) * heightsSize);
    stackSize = 0;
    i = 0;
    while (i < heightsSize) {
        if (stackSize == 0) {
            stack[stackSize++] = i++;
            continue;
        }
        if (heights[i] > heights[stack[stackSize - 1]]) {
            stack[stackSize++] = i++;
        }
        else {
            int h = heights[stack[--stackSize]];
            int left = stackSize == 0 ? -1 : stack[stackSize - 1];
            int area = (i - left - 1) * h;
            maxArea = area > maxArea ? area : maxArea;
        }
    }
    while (stackSize > 0) {
        int h = heights[stack[--stackSize]];
        int left = stackSize == 0 ? -1 : stack[stackSize - 1];
        int area = (i - left - 1) * h;
        maxArea = area > maxArea ? area : maxArea;
    }
    free(stack);
    return maxArea;
}


// @lc code=end

