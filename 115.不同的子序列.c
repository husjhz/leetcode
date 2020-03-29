/*
 * @lc app=leetcode.cn id=115 lang=c
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.31%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 21.3K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 示例 1:
 * 
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2:
 * 
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start

/*
 * 输入: S = "babgbag", T = "bag"
 *   0 b a b g b a g
 * 0 1 1 1 1 1 1 1 1 
 * b 0 1 1 2 2 3 3 3
 * a 0 0 1 1 1 1 4 4
 * g 0 0 0 0 1 1 1 5
 * dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
 * dp[i][j] = dp[i][j-1]
 */

int numDistinct(char * s, char * t){
    long **dp;
    int m = strlen(t);
    int n = strlen(s);
    int i, j;

    if (n < m) {
        return 0;
    }
    dp = (long **)malloc(sizeof(long *) * (m + 1));
    for (i = 0; i < m + 1; i++) {
        dp[i] = (long *)malloc(sizeof(long) * (n + 1));
    }
    for (i = 1; i < m + 1; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j < n + 1; j++) {
        dp[0][j] = 1;
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}


// @lc code=end

