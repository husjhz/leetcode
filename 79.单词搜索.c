/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.60%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 86.3K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * 示例:
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 */

// @lc code=start
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int backtrace(char **board, int m, int n, int x, int y, int **maps, char *word)
{
    int i;
    int xpos[] = {0, 0, -1, 1};
    int ypos[] = {-1, 1, 0, 0};
    int xx, yy;

    if (*word == '\0') {
        return true;
    }
    for (i = 0; i < 4; i++) {
        xx = xpos[i] + x;
        yy = ypos[i] + y;
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && maps[xx][yy] == 0) {
            if (board[xx][yy] == *word) {
                //printf("%c", *word);
                maps[xx][yy] = 1;
                if (backtrace(board, m, n, xx, yy, maps, word + 1)) {
                    return true;
                } else {
                    maps[xx][yy] = 0;
                }
            }
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int m, n;
    int **maps;
    int i, j;
    int wordSize;

    if (board == NULL || boardSize == 0 || word == NULL) {
        return false;
    }
    m = boardSize;
    n = *boardColSize;
    wordSize = strlen(word);
    if (wordSize > m * n) {
        return false;
    }
    maps = (int**)malloc(sizeof(int*) * m);
    for (i = 0; i < m; i++) {
        maps[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            maps[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                maps[i][j] = 1;
                //printf("%c", *word);
                if (backtrace(board, m, n, i, j, maps, word + 1)) {
                    return true;
                }
                else {
                    maps[i][j] = 0;
                }
            }
        }
    }
    return false;
}
#if 0
int main(void)
{
     char *board[3] = {
         (char[]){'A','B','C','E'},
         (char[]){'S','F','C','S'},
         (char[]){'A','D','E','E'}
     };
     int boardColSize = 4;

     if (exist(board, 3, &boardColSize, "ABCCED")) {
         printf("exist\n");
     }
     return 0;
}
#endif
// @lc code=end

