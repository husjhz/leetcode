/*
 * @lc app=leetcode.cn id=322 lang=c
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 203.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start

static inline int MIN (int a, int b)
{
    return a < b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount){
    int a;
    int i;
    int *dp;
    
    dp = (int *)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (i = 1; i < amount + 1; i++) {
        dp[i] = amount + 1;
    }
    for (a = 1; a < amount + 1; a++) {
        for (i = 0; i < coinsSize; i++) {
            if (a < coins[i]) {
                continue;
            }
            dp[a] = MIN(dp[a], 1 + dp[a - coins[i]]);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}


// @lc code=end

