/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.53%)
 * Likes:    848
 * Dislikes: 0
 * Total Accepted:    175.9K
 * Total Submissions: 490.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 *
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 *
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 *
 */

// @lc code=start
char * longestCommonPrefix2(char *str1, char *str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int minsize = size1 < size2 ? size1 : size2;
    char *tmp1 = str1, *tmp2 = str2;
    char *res;
    int i = 0;

    res = (char*)malloc(minsize + 1);
    while (*tmp1 != '\0' && *tmp2 != '\0') {
        if (*tmp1 == *tmp2) {
            res[i++] = *tmp1;
        }
        else {
            break;
        }
        tmp1++;
        tmp2++;
    }
    res[i] = '\0';
    free(str1);
    return res;
}

char * longestCommonPrefix(char ** strs, int strsSize) {
    int i;
    char *res;
    int size;

    if (strsSize == 1) {
        return strs[0];
    }
    else if (strsSize == 0) {
        return "";
    }

    size = strlen(strs[0]);
    res = (char*)malloc(size + 1);
    strcpy(res, strs[0]);
    res[size] = '\0';
    for (i = 1; i < strsSize; i++) {
        res = longestCommonPrefix2(res, strs[i]);
        if (*res == '\0') {
            break;
        }
    }
    return res;
}

// @lc code=end

