/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (38.04%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 82.5K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start
char result[100];

char * convertToTitle(int n){
    char tables[26];
    int i, j, k;
    char tmp;

    for (i = 0; i < 26; i++) {
        tables[i] = 'A' + i;
    }
    k = 0;
    while (n > 0) {
        result[k++] = tables[(n - 1) % 26];
        n = (n - 1) / 26;
    }
    result[k] = '\0';
    i = 0;
    j = k - 1;
    while (i < j) {
        tmp = result[i];
        result[i++] = result[j];
        result[j--] = tmp;
    }
    return result;
}


// @lc code=end
