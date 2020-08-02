/*
 * @lc app=leetcode.cn id=414 lang=c
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (35.23%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 86.7K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */

// @lc code=start


int thirdMax(int* nums, int numsSize){
    long long arr[4] = {LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN};
    int i, j, k;

    for (i = 0; i < numsSize; i++) {
        arr[0] = nums[i];
        for (j = 1; j < 4; j++) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
            else if (arr[j - 1] == arr[j]) {
                for (k = j - 1; k > 0; k--) {
                    arr[k] = arr[k - 1];
                }
                break;
            }
        }
    }
    return arr[1] == LONG_MIN ? arr[3] : arr[1];
}


// @lc code=end
