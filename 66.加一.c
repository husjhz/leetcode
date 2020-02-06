/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.15%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    112.5K
 * Total Submissions: 263.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *returnArray;
    int i, j;
    int carry = 0;

    *returnSize = 0;
    if (digits == NULL || digitsSize == 0) {
        return NULL;
    }
    returnArray = (int*)malloc(sizeof(int) * (digitsSize + 1));
    for (i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            break;
        }
    }
    if (i == -1) {
        returnArray[0] = 1;
        for (j = 1; j < digitsSize + 1; j++) {
            returnArray[j] = 0;
        }
        *returnSize = digitsSize + 1;
    }
    else {
        for (j = 0; j < i; j++) {
            returnArray[j] = digits[j];
        } 
        returnArray[i] = digits[i] + 1;
        for (j = i + 1; j < digitsSize; j++) {
            returnArray[j] = 0;
        }
        *returnSize = digitsSize;
    }
    return returnArray;
}


// @lc code=end

