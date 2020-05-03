/*
 * @lc app=leetcode.cn id=529 lang=c
 *
 * [529] 扫雷游戏
 *
 * https://leetcode-cn.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (59.28%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 9.5K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 * 
 * 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B'
 * 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X'
 * 则表示一个已挖出的地雷。
 * 
 * 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
 * 
 * 
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
 * 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
 * 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回面板。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入矩阵的宽和高的范围为 [1,50]。
 * 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
 * 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
 * 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
 * 
 */

// @lc code=start
#include <stddef.h>

void dfs(char **board, int m, int n, int row, int col, int **visited)
{
    int i;
    int x, y;
    int xpos[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int ypos[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int count = 0;

    visited[row][col] = 1;
    for (i = 0; i < 8; i++) {
        x = xpos[i] + row;
        y = ypos[i] + col;
        if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0) {
            if (board[x][y] == 'M') {
                count++;
            }
        }
    }
    if (count > 0) {
        board[row][col] = count + '0';
    }
    else if (board[row][col] == 'E') {
        board[row][col] = 'B';
        for (i = 0; i < 8; i++) {
            x = xpos[i] + row;
            y = ypos[i] + col;
            if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0) {
                dfs(board, m, n, x, y, visited);
            }
        }
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int m, n;
    int row, col;
    int i, j;
    int **visited;
    int count;

    *returnSize = 0;
    if (board == NULL || boardSize == 0) {
        return NULL;
    }
    m = boardSize;
    n = *boardColSize;
    row = click[0];
    col = click[1];
    *returnSize = boardSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    if (row < 0 || row >= m || col < 0 || col >= n) {
        return board;
    }
    visited = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        visited[i] = (int *)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    if (board[row][col] == 'M') {
        board[row][col] = 'X';
    }
    else if (board[row][col] == 'E') {
        dfs(board, m, n, row, col, visited);
    }
    return board;
}


// @lc code=end

