/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (39.47%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    49K
 * Total Submissions: 122.4K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
int partion(int **nums, int left, int right)
{
    int tmp1, tmp2;

    tmp1 = nums[left][0];
    tmp2 = nums[left][1];
    while (left < right) {
        while (left < right && nums[right][0] >= tmp1) {
            right--;
        }
        nums[left][0] = nums[right][0];
        nums[left][1] = nums[right][1];
        while (left < right && nums[left][0] <= tmp1) {
            left++;
        }
        nums[right][0] = nums[left][0];
        nums[right][1] = nums[left][1];
    }
    nums[left][0] = tmp1;
    nums[left][1] = tmp2;
    return left;
}

void quicksort(int **nums, int left, int right)
{
    if (left < right) {
        int mid = partion(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    }
}

static inline int MAX(int a, int b)
{
    return a > b ? a : b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int **returnArray;
    int cur;

    *returnSize = 0;
    if (intervals == NULL || intervalsSize == 0) {
        return NULL;
    }
    returnArray = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);
    quicksort(intervals, 0, intervalsSize - 1);
    cur = 1;
    while (cur < intervalsSize) {
        if (intervals[cur][0] > intervals[cur - 1][1]) {
            returnArray[*returnSize] = (int*)malloc(sizeof(int) * 2);
            returnArray[*returnSize][0] = intervals[cur - 1][0];
            returnArray[*returnSize][1] = intervals[cur - 1][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        else {
            intervals[cur][0] = intervals[cur - 1][0];
            intervals[cur][1] = MAX(intervals[cur][1], intervals[cur - 1][1]);
        }
        cur++;
    }
    returnArray[*returnSize] = (int*)malloc(sizeof(int) * 2);
    returnArray[*returnSize][0] = intervals[cur - 1][0];
    returnArray[*returnSize][1] = intervals[cur - 1][1];
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;
    return returnArray;
}


// @lc code=end

