/*
 * @lc app=leetcode.cn id=97 lang=c
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (37.82%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 26K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */

// @lc code=start
#include <stddef.h>
#include <stdbool.h>

bool isInterleave(char * s1, char * s2, char * s3){
    int m = strlen(s1);
    int n = strlen(s2);
    int k = strlen(s3);
    int **dp;
    int i, j;

    if (k > m + n) {
        return false;
    }
    if (m == 0 && n != k || n == 0 && m != k) {
        return false;
    }
    dp = (int**)malloc((m + 1) * sizeof(int*));
    for (i = 0; i < m + 1; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    dp[0][0] = 1;
    for (i = 1; i < m + 1; i++) {
        dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
    }
    for (j = 1; j < n + 1; j++) {
        dp[0][j] = (s2[j - 1] == s3[j - 1]) && dp[0][j - 1];
    }
    for (i = 1; i < m + 1; i++) {
        for (j = 1; j < n + 1; j++) {
            dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) | \
                (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
        }
    }
    return dp[m][n];
}


// @lc code=end

