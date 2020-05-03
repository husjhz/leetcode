/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (67.04%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 35.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char **getBoard(char **src, int n)
{
    char **board;
    int i, j;

    board = (char **)malloc(sizeof(char *) * n);
    for (i = 0; i < n; i++) {
        board[i] = (char *)malloc(sizeof(char) * (n + 1));
        if (src) {
            memcpy(board[i], src[i], n + 1);
        }
        else {
            memset(board[i], '.', n);
            board[i][n] = '\0';
        }
    } 
    return board;  
}

int isVaild(char **board, int n, int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
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

void backtrace(char **board, int n, int row, char ***returnArray, int *returnSize, int **returnColumnSizes)
{
    int col;

    if (row == n) {
        returnArray[*returnSize] = getBoard(board, n);
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    for (col = 0; col < n; col++) {
        if (!isVaild(board, n, row, col)) {
            continue;
        }
        board[row][col] = 'Q';
        backtrace(board, n, row + 1, returnArray, returnSize, returnColumnSizes);
        board[row][col] = '.';
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char **board;
    char ***returnArray;
    int k;

    board = getBoard(NULL, n);
    returnArray = (char ***)malloc(sizeof(char **) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    backtrace(board, n, 0, returnArray, returnSize, returnColumnSizes);
    return returnArray;
}


// @lc code=end

