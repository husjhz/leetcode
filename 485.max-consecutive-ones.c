/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.66%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    46.2K
 * Total Submissions: 81.6K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */

// @lc code=start


int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i, j;
    int max = 0;

    // 1 0 1 1 0 1
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            //printf("i = %d\n", i);
            for (j = i + 1; j < numsSize; j++) {
                if (nums[j] == 0) {
                    break;
                }
            }
            //printf("j = %d\n", j);
            max = j - i >  max ? j - i : max;
            i = j;
        }
    }
    return max;
}


// @lc code=end
