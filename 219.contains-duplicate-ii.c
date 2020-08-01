/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (39.79%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 135.2K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的
 * 绝对值 至多为 k。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */

// @lc code=start
void bubble_sort(int *nums, int numsSize, int *pos)
{
    int i, j;
    int tmp;
    int flag;

    for (i = 0; i < numsSize - 1; i++) {
        flag = 0;
        for (j = 1; j < numsSize - i; j++) {
            if (nums[j - 1] > nums[j]) {
                tmp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = tmp;
                tmp = pos[j - 1];
                pos[j - 1] = pos[j];
                pos[j] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int *pos;
    int i;

    if (numsSize < 2) {
        return false;
    } 
    pos = (int *)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        pos[i] = i;
    }
    bubble_sort(nums, numsSize, pos);
    //for (i = 0; i < numsSize; i++) {
    //    printf("[%d]%d ", pos[i], nums[i]);
    //}
    //printf("\n");
    for (i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            if (pos[i] - pos[i - 1] <= k) {
                return true;
            }
        }
    }
    return false;
}


// @lc code=end
