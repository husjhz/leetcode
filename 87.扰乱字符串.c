/*
 * @lc app=leetcode.cn id=87 lang=c
 *
 * [87] 扰乱字符串
 *
 * https://leetcode-cn.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (44.67%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 15K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
 * 
 * 下图是字符串 s1 = "great" 的一种可能的表示形式。
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
 * 
 * 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
 * 
 * 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
 * 
 * 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "great", s2 = "rgeat"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "abcde", s2 = "caebd"
 * 输出: false
 * 
 */

// @lc code=start
#include <stddef.h>
#include <stdbool.h>

bool isScramble(char * s1, char * s2){
    int m = strlen(s1);
    int n = strlen(s2);
    int ***dp;
    int i, j, k;
    int len;

    if (m != n) {
        return false;
    }
    dp = (int***)malloc(sizeof(int**) * n);
    for (i = 0; i < n; i++) {
        dp[i] = (int**)malloc(sizeof(int*) * n);
        for (j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc(sizeof(int) * (n + 1));
            for (k = 0; k < n + 1; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j][1] = (s1[i] == s2[j]);
        }
    }
    for (len = 2; len <= n; len++) {
        for (i = 0; i <= n - len; i++) {
            for (j = 0; j <= n - len; j++) {
                for (k = 1; k <= len - 1; k++) {
                    if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                }
            }
        }
    }
    return dp[0][0][n];
}


// @lc code=end

