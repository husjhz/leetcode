/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (36.54%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    28.9K
 * Total Submissions: 78K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *
 *
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 示例 1:
 *
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 *
 */

// @lc code=start
#include <stdbool.h>
#include <stddef.h>

int binarySearch(int **nums, int m, int n, int left, int right, int target)
{
    int mid;
    int x, y;

    if (left > right) {
        return -1;
    }
    mid = left + (right - left) / 2;
    x = mid / n;
    y = mid - (n * x);
    if (nums[x][y] == target) {
        return mid;
    }
    else if (nums[x][y] < target) {
        return binarySearch(nums, m, n, mid + 1, right, target);
    }
    else { 
        return binarySearch(nums, m, n, left, mid - 1, target);
    }
}

bool searchMatrix(int **matrix, int matrixSize, int* matrixColSize, int target){
    int m, n;
    int k;
    int index;
    int i, j;

    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        return false;
    }
    m = matrixSize;
    n = *matrixColSize;
    index = binarySearch(matrix, m, n, 0, m * n - 1, target);
    return index >= 0;
}
#if 0
int main(void)
{
    int *matrix[3] = {(int[]){1,3,5,7},(int[]){10,11,16,20},(int[]){23,30,34,50}};
    int matrixColSize = 4;

    searchMatrix(matrix, 3, &matrixColSize, 3);

    return 0;
}
#endif
// @lc code=end

