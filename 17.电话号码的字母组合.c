/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.70%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    71.2K
 * Total Submissions: 136.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int dictSize[8] = {3, 3, 3, 3, 3, 4, 3, 4};
void dfs(char *digits, int size, char *stack, int top, char **res, int *index)
{
    int i, j;
    if (size == 1) {
        for (i = 0; i < dictSize[digits[0] - '2']; i++) {
            stack[top] = dict[digits[0] - '2'][i];
            for (j = 0; j <= top; j++) {
                res[*index][j] = stack[j];
            }
            res[*index][j] = '\0';
            (*index)++;
        }
    }
    else {
        for (i = 0; i < dictSize[digits[0] - '2']; i++) {
            stack[top] = dict[digits[0] - '2'][i];
            dfs(digits + 1, size - 1, stack, top + 1, res, index);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char *tmp = digits;
    int len = strlen(digits);
    int size = 1;
    char **res;
    int i;
    int index = 0;
    char *stack;

    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }
    while (*tmp != '\0') {
        size *= dictSize[*tmp - '2'];
        tmp++;
    }
    res = (char**)malloc(sizeof(char*) * size);
    for (i = 0; i < size; i++) {
        res[i] = (char*)malloc(sizeof(char) * (len + 1));
    }
    stack = (char*)malloc(sizeof(char) * 100);
    dfs(digits, len, stack, 0, res, &index);
    *returnSize = size;
    free(stack);
    return res;
}


// @lc code=end

