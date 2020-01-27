/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.32%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 159.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
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
    int index;
    if (left < right) {
        index = partion(array, left, right);
        quicksort(array, left, index - 1);
        quicksort(array, index + 1, right);
    }
}

static inline ABS(int a)
{
    return a < 0 ? -a : a;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i, j, k;
    int newTarget;
    int diff;
    int minDiff = INT_MAX;
    int closeTarget;

    quicksort(nums, 0, numsSize -1);
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        newTarget = target - nums[i];
        while (j < k) {
            if (nums[j] + nums[k] == newTarget) {
                return target;
            }
            else if (nums[j] + nums[k] < newTarget) {
                diff = newTarget - (nums[j] + nums[k]);
                if (diff < minDiff) {
                    minDiff = diff;
                    closeTarget = nums[i] + nums[j] + nums[k];
                }
                j++;
            }
            else {
                diff = (nums[j] + nums[k]) - newTarget;
                if (diff < minDiff) {
                    minDiff = diff;
                    closeTarget = nums[i] + nums[j] + nums[k];
                }
                k--;
            }
        }   
    }
    return closeTarget;
}

// @lc code=end

