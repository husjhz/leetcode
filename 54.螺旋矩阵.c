/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (37.86%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 98.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *returnArray;
    int rowSize;
    int colSize;
    int **maps;
    int i, j, k;
    int sel;
    int xpos[] = {0, 1, 0, -1};
    int ypos[] = {1, 0, -1, 0};

    *returnSize = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) {
        return NULL;
    }
    rowSize = matrixSize;
    colSize = matrixColSize[0];
    returnArray = (int*)malloc(sizeof(int) * rowSize * colSize);
    maps = (int**)malloc(sizeof(int*) * rowSize);
    for (i = 0; i < rowSize; i++) {
        maps[i] = (int*)malloc(sizeof(int) * colSize);
    }
    i = 0;
    j = 0;
    sel = 0;
    for (k = 0; k < rowSize * colSize; k++) {
        int ii, jj;
        returnArray[k] = matrix[i][j];
        maps[i][j] = 1;
        ii = i + xpos[sel];
        jj = j + ypos[sel];
        if (ii >= 0 && ii < rowSize && jj >= 0 && jj < colSize && maps[ii][jj] != 1) {
            i = ii;
            j = jj;
        }
        else {
            sel = (sel + 1) % 4;
            i += xpos[sel];
            j += ypos[sel];
        }
    }
    *returnSize = rowSize * colSize;
    free(maps);
    return returnArray;
}


// @lc code=end

