/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (67.53%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    58.3K
 * Total Submissions: 85.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 *
 *
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 */

// @lc code=start
static int partion(int *nums, int left, int right)
{
    int target = nums[left];

    while (left < right) {
        while (left < right && nums[right] >= target) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= target) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = target;
    return left;
}

static void quicksort(int *nums, int left, int right)
{
    if (left < right) {
        int mid = partion(nums, left, right);
        quicksort(nums, left, mid - 1);
        quicksort(nums, mid + 1, right);
    }
}

struct stack {
    int *array;
    int capacity;
    int size;
};

static struct stack *create(int capacity)
{
    struct stack *s;

    s = (struct stack*)malloc(sizeof(struct stack));
    s->array = (int*)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size = 0;
    return s;
}

static int push(struct stack *s, int x)
{
    if (s->size == s->capacity) {
        return -1;
    }
    s->array[s->size++] = x;
    return s->size;
}

static int pop(struct stack *s, int *px)
{
    if (s->size == 0) {
        return -1;
    }
    *px = s->array[--s->size];
    return s->size;
}

int isDuplicate(struct stack *s, int *returnSize, int **returnArray, int **returnColumnSizes)
{
    int i, j;
    int count;

    quicksort(s->array, 0, s->size - 1);
    if (*returnSize == 0) {
        return 0;
    }
    for (i = 0; i < *returnSize; i++) {
        if (s->size != (*returnColumnSizes)[i]) {
            continue;
        }
        count = 0;
        for (j = 0; j < s->size; j++) {
            if (s->array[j] != returnArray[i][j]) {
                break;
            }
            count++;
        }
        if (count == s->size) {
            return 1;
        }
    }
    return 0;
}

void dfs(int *candidates, int start, int end, int target, struct stack *s,
    int *returnSize, int **returnArray, int **returnColumnSizes)
{
    int i;
    int data;

    if (target == 0) {
        if (isDuplicate(s, returnSize, returnArray, returnColumnSizes)) {
            return;
        }
        returnArray[*returnSize] = (int*)malloc(sizeof(int) * s->size);
        memcpy(returnArray[*returnSize], s->array, sizeof(int) * s->size);
        (*returnColumnSizes)[*returnSize] = s->size;
        (*returnSize)++;
        return;
    }
    for (i = start; i <= end && target - candidates[i] >= 0; i++) {
        push(s, candidates[i]);
        dfs(candidates, i, end, target - candidates[i], s, returnSize, returnArray, returnColumnSizes);
        pop(s, &data);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **returnArray;
    int allocSizes = 1000;
    struct stack *stack;
    int i;

    *returnSize = 0;
    if (candidates == NULL || candidatesSize == 0) {
        return NULL;
    }
    quicksort(candidates, 0, candidatesSize - 1);
    returnArray = (int**)malloc(sizeof(int*) * allocSizes);
    *returnColumnSizes = (int*)malloc(sizeof(int) * allocSizes);
    stack = create(allocSizes);
    dfs(candidates, 0, candidatesSize - 1, target, stack, returnSize, returnArray, returnColumnSizes);

    return returnArray;
}

/*
直接上回溯算法框架。解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。

2、选择列表：也就是你当前可以做的选择。

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

代码方面，回溯算法的框架：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

for 选择 in 选择列表:
    做选择
    backtrack(路径, 选择列表)
    撤销选择
其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」，特别简单。
*/

// @lc code=end

