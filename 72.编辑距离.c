/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (55.31%)
 * Likes:    494
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 46K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */

// @lc code=start
static inline int MIN(int a, int b, int c)
{
    int d;
    d = a < b ? a : b;
    return c < d ? c : d;
}

int minDistance(char * word1, char * word2){
    int **dp;
    int m = strlen(word1);
    int n = strlen(word2);
    int i, j;

    dp = (int**)malloc(sizeof(int*) * (m + 1));
    for (i = 0; i < m + 1; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
    }
    dp[0][0] = 0;
    for (i = 1; i < m + 1; i++) {
        dp[i][0] = i;
    }
    for (j = 1; j < n + 1; j++) {
        dp[0][j] = j;
    }
    for (i = 1; i < m + 1; i++) {
        for (j = 1; j < n + 1; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = MIN(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[m][n];
}


// @lc code=end

