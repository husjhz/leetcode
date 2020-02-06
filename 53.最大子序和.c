/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.39%)
 * Likes:    1543
 * Dislikes: 0
 * Total Accepted:    149.5K
 * Total Submissions: 306.3K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
static inline MAX(int a, int b)
{
    return a > b ? a : b;
}

#if 0
int maxSubArray(int* nums, int numsSize){
    int currentSum;
    int maxSum;
    int i;

    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    currentSum = nums[0];
    maxSum = nums[0];
    for (i = 1; i < numsSize; i++) {
        currentSum = MAX(nums[i], currentSum + nums[i]);
        maxSum = MAX(currentSum, maxSum);
    }
    return maxSum;
}
#else
int calcMidMaxSum(int *nums, int left, int mid, int right)
{
    int leftMaxSum = INT_MIN;
    int rightMaxSum = INT_MIN;
    int i;
    int sum;

    sum = 0;
    for (i = mid; i >=0; i--) {
        sum += nums[i];
        leftMaxSum = MAX(sum, leftMaxSum);
    }
    sum = 0;
    for (i = mid + 1; i <= right; i++) {
        sum += nums[i];
        rightMaxSum = MAX(sum, rightMaxSum);
    }
    return leftMaxSum + rightMaxSum;
}

int maxSubArray2(int *nums, int left, int right)
{
    int leftSum;
    int rightSum;
    int mid;
    int midSum;

    if (left == right) {
        return nums[left];
    }
    mid = left + (right - left) / 2;
    leftSum = maxSubArray2(nums, left, mid);
    rightSum = maxSubArray2(nums, mid + 1, right);
    midSum = calcMidMaxSum(nums, left, mid, right);
    return MAX(MAX(leftSum, rightSum), midSum);
}

int maxSubArray(int* nums, int numsSize){
    return maxSubArray2(nums, 0, numsSize - 1);
}
#endif

// @lc code=end

