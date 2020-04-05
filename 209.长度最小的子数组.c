/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.71%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 79.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */

// @lc code=start
static inline int MIN(int a, int b)
{
    return a < b ? a : b;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    int left = 0;
    int right = 0;
    int ans = INT_MAX;
    int sum = 0;
    
    if (!nums || numsSize == 0) {
        return 0;
    }
    while (left <= right && right < numsSize) {
        sum += nums[right];
        while (sum >= s) {
            ans = MIN(ans, right - left + 1);
            if (ans == 1) {
                goto out;
            }
            sum -= nums[left];
            left++;
        }
        right++;
    }
out:
    if (ans == INT_MAX) {
        ans = 0;
    }
    return ans;
}


// @lc code=end

