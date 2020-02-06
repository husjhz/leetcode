/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (63.57%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    54.3K
 * Total Submissions: 84.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
static int MIN(int a, int b)
{
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m, n;
    int **dp;
    int i, j;
    int minSum;

    if (grid == NULL || gridSize == 0) {
        return 0;
    }
    m = gridSize;
    n = *gridColSize;
    dp = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = grid[0][0];
    for (i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + MIN(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    minSum = dp[m - 1][n - 1];
    free(dp);
    return minSum;
}


// @lc code=end

