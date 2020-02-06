/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (76.50%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 18.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start


int isValid(int **board, int n, int row, int col)
{
    int i, j;

    for (i = 0; i <= row; i++) {
        if (board[i][col] == 'Q') {
            return 0;
        }
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
    return 1;
}

void backtrace(int **board, int n, int row, int *returnSize)
{
    int j;

    if (row == n) {
        (*returnSize)++;
        return;
    }
    for (j = 0; j < n; j++) {
        if (isValid(board, n, row, j)) {
            board[row][j] = 'Q';
            backtrace(board, n, row + 1, returnSize);
            board[row][j] = '.';
        }
    }
}

int totalNQueens(int n){
    int **board;
    int i;
    int returnSize = 0;

    if (n == 1) {
        return 1;
    }
    else if (n < 4) {
        return 0;
    }
    board = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        board[i] = (int*)malloc(sizeof(int) * n);
    }
    backtrace(board, n, 0, &returnSize);
    return returnSize;
}


// @lc code=end

