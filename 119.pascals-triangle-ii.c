/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (61.44%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    62K
 * Total Submissions: 100.9K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *result;
    int i, j;

    result = (int *)malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;
    if (rowIndex == 0) {
        result[0] = 1;
    }
    else if (rowIndex == 1) {
        result[0] = 1;
        result[1] = 1;
    }
    else {
        result[0] = 1;
        result[1] = 1;
        for (i = 2; i < rowIndex + 1; i++) {
            result[i] = 1; 
            for (j = i - 1; j >= 1; j--) {
                result[j] = result[j] + result[j - 1];
            }
        }
    }
    return result;
}


// @lc code=end
