/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.78%)
 * Likes:    1728
 * Dislikes: 0
 * Total Accepted:    146.2K
 * Total Submissions: 580.8K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例：
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int partion(int *array, int left, int right)
{
    int tmp = array[left];

    while (left < right) {
        while (left < right && array[right] >= tmp) {
            right--;
        }
        array[left] = array[right];
        while (left < right && array[left] <= tmp) {
            left++;
        }
        array[right] = array[left];
    }
    array[left] = tmp;
    return left;
}

static void quicksort(int *array, int left, int right)
{
    if (left < right) {
        int index = partion(array, left, right);
        quicksort(array, left, index - 1);
        quicksort(array, index + 1, right);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k;
    int target;
    int index = -1;
    int **returnColumn;

    quicksort(nums, 0, numsSize - 1);
    *returnColumnSizes = (int*)malloc(100000 * sizeof(int));
    returnColumn = (int**)malloc(100000 * sizeof(int*));
    for (i = 0; i < numsSize - 2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            j = i + 1;
            k = numsSize - 1;
            target = 0 - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    index++;
                    (*returnColumnSizes)[index] = 3;
                    returnColumn[index] = (int*)malloc(sizeof(int) * 3);
                    returnColumn[index][0] = nums[i];
                    returnColumn[index][1] = nums[j];
                    returnColumn[index][2] = nums[k];
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target) {
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                }
                else {
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }
    }
    *returnSize = index + 1;
    return returnColumn;
}

// @lc code=end

