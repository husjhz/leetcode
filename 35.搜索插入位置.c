/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.69%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    110.9K
 * Total Submissions: 246.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start
int search(int *nums, int left, int right, int target, int *mid)
{
    if (left > right) {
        return -1;
    }
    *mid = left + (right - left) / 2;
    if (nums[*mid] == target) {
        return *mid;
    }
    else if (nums[*mid] < target) {
        return search(nums, *mid + 1, right, target, mid);
    }
    else {
        return search(nums, left, *mid - 1, target, mid);
    }
}

int searchInsert(int* nums, int numsSize, int target){
    int index;
    int mid;
    int i;

    index = search(nums, 0, numsSize - 1, target, &mid);
    if (index == -1) {
        if (nums[mid] > target) {
            i = mid;
            while (i >= 0 && nums[i] > target) {
                i--;
            }
            index = i + 1;
        }
        else {
            i = mid;
            while (i <= numsSize - 1 && nums[i] < target) {
                i++;
            }
            index = i;
        }
    }
    return index;
}


// @lc code=end

