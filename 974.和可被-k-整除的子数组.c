/*
 * @lc app=leetcode.cn id=974 lang=c
 *
 * [974] 和可被 K 整除的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (37.39%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 7.6K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [4,5,0,-2,-3,1], K = 5
 * 输出：7
 * 解释：
 * 有 7 个子数组满足其元素之和可被 K = 5 整除：
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 * 
 * 
 */

// @lc code=start
#include <stddef.h>

// 1 2 3 4 5
// 1 2 3 4 5
// 12 23 34 45
// 123 234 345 
// 1234 2345
// 12345

int subarraysDivByK(int* A, int ASize, int K){
    long sum = 0;
    int i;
    int *count;
    int tmp;
    int res = 0;

    if (A == NULL || ASize == 0) {
        return 0;
    }
    count = (int *)malloc(sizeof(int) * K);
    for (i = 0; i < K; i++) {
        count[i] = 0;
    }
    count[0] = 1;
    for (i = 0; i < ASize; i++) {
        sum += A[i];
        tmp = sum % K;
        if (tmp < 0) {
            tmp += K;
        }
        res += count[tmp];
        count[tmp]++;
    }
    return res;
}


// @lc code=end

