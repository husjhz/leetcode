/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.26%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 147K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int search(int *nums, int left, int right, int target)
{
    int mid;

    if (left > right || nums[left] > target || nums[right] < target) {
        return -1;
    }
    mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    else if (nums[mid] < target) {
        return search(nums, mid + 1, right, target);
    }
    else {
        return search(nums, left, mid - 1, target);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int index;
    int *returnArray;
    int i;

    *returnSize = 2;
    returnArray = (int*)malloc(sizeof(int) * 2);
    index = search(nums, 0, numsSize - 1, target);
    if (index < 0) {
        returnArray[0] = -1;
        returnArray[1] = -1;
        return returnArray;
    }
    *returnSize = 2;
    
    i = index;
    while (i >= 0 && nums[i] == target) {
        i--;
    }
    returnArray[0] = i + 1;
    i = index;
    while (i <= numsSize - 1 && nums[i] == target) {
        i++;
    }
    returnArray[1] = i - 1;
    return returnArray;
}


// @lc code=end

