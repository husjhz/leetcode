/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.32%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    38.5K
 * Total Submissions: 118.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
void reverse(int *nums, int left, int right)
{
    int tmp;
    while (left < right) {
        tmp = nums[right];
        nums[right] = nums[left];
        nums[left] = tmp;
        left++;
        right--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i;
    int tmp;

    if (nums == NULL || numsSize < 2) {
        return;
    }
    i = numsSize - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        tmp = nums[i];
        nums[i] = nums[j]; 
        nums[j] = tmp;
    }
    reverse(nums, i + 1, numsSize - 1);
}


// @lc code=end

