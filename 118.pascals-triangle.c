/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (66.88%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    93.7K
 * Total Submissions: 140.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **returnArray;
    int i, j;

    *returnSize = numRows;
    if (numRows < 1) 
        return NULL;
    returnArray = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    for (i = 0; i < numRows; i++) {
        returnArray[i] = (int *)malloc(sizeof(int) * numRows);
        returnArray[i][0] = 1;
        returnArray[i][i] = 1;
    }
    (*returnColumnSizes)[0] = 1;
    if (numRows > 1) 
        (*returnColumnSizes)[1] = 2;
    for (i = 2 ; i < numRows; i++) {
        for (j = 1; j < i; j++) {
            returnArray[i][j] = returnArray[i - 1][j - 1] + returnArray[i - 1][j];
        }
        (*returnColumnSizes)[i] = i + 1;
    }
    return returnArray;
}


// @lc code=end
