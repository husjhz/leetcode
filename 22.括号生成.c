/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.57%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    67.9K
 * Total Submissions: 93.1K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 *
 * 例如，给出 n = 3，生成结果为：
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 *
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static void dfs(int n, char *str, char **res, int *resNum, int left, int right)
{
    if (left + right == 2 * n) {
        res[*resNum] = (char*)malloc(2 * n + 1);
        strcpy(res[*resNum], str);
        res[*resNum][2 * n] = '\0';
        (*resNum)++;
        return;
    }
    if (left < n) {
        strcat(str, "(");
        dfs(n, str, res, resNum, left + 1, right);
        str[left + right] = '\0';
    }
    if (left > right) {
        strcat(str, ")");
        dfs(n, str, res, resNum, left, right + 1);
        str[left + right] = '\0';
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char **res;
    char *str;
    int resNum = 0;

    str = (char*)malloc(2 * n + 1);
    *str = '\0';
    res = (char**)malloc(sizeof(char*) * 100000);
    dfs(n, str, res, &resNum, 0, 0);
    *returnSize = resNum;
    return res;
}

// @lc code=end

