/*
 * @lc app=leetcode.cn id=132 lang=c
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (42.12%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 20.2K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的最少分割次数。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

int check(char *s, int left, int right)
{
    while (left < right) {
        if (s[left] != s[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int MIN(int a, int b)
{
    return a < b ? a : b;
}

int minCut(char * s){
    int *dp;
    int len;
    int i, j;

    if (s == NULL || *s == '\0') {
        return 0;
    }
    len = strlen(s);
    if (len == 1) {
        return 0;
    }
    dp = (int *)malloc(sizeof(int) * (len + 1));
    dp[0] = -1;
    for (i = 1; i <= len; i++) {
        dp[i] = i;
        for (j = 0; j < i; j++) {
            if (check(s, j, i - 1)) {
                dp[i] = MIN(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[len];
}


// @lc code=end

