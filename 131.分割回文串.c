/*
 * @lc app=leetcode.cn id=131 lang=c
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (65.83%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 38.4K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stddef.h>

#define MAX_SIZE    10000
int check(char *s, int start, int end) 
{
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void dfs(char *s, int pos, int *result, int idx, char ***returnArray, int *returnSize, int **returnColumnSizes)
{
    int i, j, k;

    if (s[pos] == '\0') {
        returnArray[*returnSize] = (char **)malloc(sizeof(char *) * (idx - 1));
        for (i = 1; i < idx; i++) {
            returnArray[*returnSize][i - 1] = (char *)malloc(sizeof(char) * (result[i] - result[i - 1] + 1));
            k = 0;
            for (j = result[i - 1] + 1; j <= result[i]; j++) {
                returnArray[*returnSize][i - 1][k++] = s[j];
            }
            returnArray[*returnSize][i - 1][k] = '\0';
        }
        (*returnColumnSizes)[*returnSize] = idx - 1;
        (*returnSize)++;
        return;
    }
    for (i = pos; s[i] != '\0'; i++) {
        if (check(s, pos, i)) {
            result[idx] = i;
            dfs(s, i + 1, result, idx + 1, returnArray, returnSize, returnColumnSizes);
        }
    }
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    char ***returnArray;
    int *result;
    int len;

    *returnSize = 0;
    if (s == NULL || *s == '\0') {
        return NULL;
    }
    len = strlen(s);
    returnArray = (char ***)malloc(sizeof(char **) * MAX_SIZE);
    *returnColumnSizes = (int **)malloc(sizeof(int) * MAX_SIZE);
    result = (int *)malloc(sizeof(int) * (len + 1));
    result[0] = -1;
    dfs(s, 0, result, 1, returnArray, returnSize, returnColumnSizes);
    return returnArray;
}


// @lc code=end

