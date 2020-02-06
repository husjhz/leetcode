/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 113.2K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 *
 * 说明：m 和 n 的值均不超过 100。
 *
 * 示例 1:
 *
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 *
 *
 * 示例 2:
 *
 * 输入: m = 7, n = 3
 * 输出: 28
 *
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

#if 1
int backtrace(int m, int n, int x, int y, int **dp)
{
    if (x == m - 1) {
        return 1;
    }
    if (y == n - 1) {
        return 1;
    }
    if (dp[x][y] > 0) {
        return dp[x][y];
    }
    dp[x + 1][y] = backtrace(m, n, x + 1, y, dp);
    dp[x][y + 1] = backtrace(m, n, x, y + 1, dp);
    dp[x + 1][y + 1] = dp[x + 1][y] + dp[x][y + 1];
    return dp[x + 1][y + 1];
}

int uniquePaths(int m, int n){
    int **dp;
    int i, j;

    if (m <= 0 || n <= 0) {
        return 0;
    }
    if (m == 1 || n == 1) {
        return 1;
    }
    dp = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    return backtrace(m, n, 0, 0, dp);
}
#else
int uniquePaths(int m, int n){
    
}
#endif

#if 0
int main(void)
{
    int n;

    n = uniquePaths(3, 2);
    printf("%d\n", n);

    return 0;
}
#endif
// @lc code=end

