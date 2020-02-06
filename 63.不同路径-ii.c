/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.03%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    37.9K
 * Total Submissions: 117.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start
int backtrace(int **grid, int m, int n, int **dp)
{
    int i;
    if (m < 0 || n < 0) {
        return 0;
    }
    if (grid[m][n] == 1) {
        return 0;
    }
    if (m == 0) {
        for (i = 0; i < n; i++) {
            if (grid[m][i] == 1) {
                return 0;
            }
        }
        return 1;
    }
    if (n == 0) {
        for (i = 0; i < m; i++) {
            if (grid[i][n] == 1) {
                return 0;
            }
        }
        return 1;
    }
    if (dp[m][n] > 0) {
        return dp[m][n];
    }    
    dp[m][n - 1] = backtrace(grid, m, n - 1, dp);
    dp[m - 1][n] = backtrace(grid, m - 1, n, dp);
    dp[m][n] = dp[m][n - 1] + dp[m- 1][n];
    return dp[m][n];
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m, n;
    int **dp;
    int i, j;
    int res;

    if (obstacleGrid == NULL || obstacleGridSize == 0) {
        return 0;
    }
    m = obstacleGridSize;
    n = *obstacleGridColSize;
    dp = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    res = backtrace(obstacleGrid, m - 1, n - 1, dp);
    free(dp);
    return res;
}


// @lc code=end

