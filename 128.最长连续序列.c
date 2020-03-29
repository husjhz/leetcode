/*
 * @lc app=leetcode.cn id=128 lang=c
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.12%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    29.8K
 * Total Submissions: 61.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
int partion(int *nums, int left, int right)
{
    int tmp = nums[left];

    while (left < right) {
        while (left < right && nums[right] >= tmp) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= tmp) {
            left++;
        } 
        nums[right] = nums[left];
    }
    nums[left] = tmp;
    return left;
}

void quicksort(int *nums, int left, int right)
{
    int mid;

    if (left < right) {
        mid = partion(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    }
}

int longestConsecutive(int* nums, int numsSize){
    int i;
    int count = 0;
    int maxCount = 0;
    int prev, next;

    if (numsSize < 2) {
        return numsSize;
    }
    quicksort(nums, 0, numsSize - 1);
    prev = nums[0];
    count = 1;
    maxCount = 1;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == prev + 1) {
            count++;
        }
        else if (nums[i] == prev) {
            continue;
        }
        else {
            if (count > maxCount) {
                maxCount = count;  
            }
            count = 1;
        }
        prev = nums[i];
    }
    if (count > maxCount) {
        maxCount = count;
    }
    return maxCount;
}


// @lc code=end

