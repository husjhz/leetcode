/*
 * @lc app=leetcode.cn id=448 lang=c
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (59.27%)
 * Likes:    412
 * Dislikes: 0
 * Total Accepted:    46.7K
 * Total Submissions: 78.7K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int i;
    int *result;
    int j = 0;

    for (i = 0; i < numsSize; i++) {
        nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
    }
    result  = (int *)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[j++] = i + 1;
        }
    }
    *returnSize = j;

    return result;
}


// @lc code=end
