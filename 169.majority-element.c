/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (64.01%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    192.7K
 * Total Submissions: 300.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
static int comp(const void *a, const void *b)
{
    int *aa = (int *)a;
    int *bb = (int *)b;
    return *aa - *bb;
}

int majorityElement(int* nums, int numsSize){
    int i;
    int count = 1;

    if (numsSize == 1) {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), comp);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
            if (count > numsSize / 2) {
                return nums[i];
            }
        }
        else {
            count = 1;
        }
    }
    return 0;
}

// @lc code=end
