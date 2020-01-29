/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.18%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    120.3K
 * Total Submissions: 305.4K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
void getNext(char *pat, int *next)
{
    int plen = strlen(pat);
    int i = 0;
    int j = -1;

    next[0] = -1;
    while (i < plen) {
        if (j == -1 || pat[i] == pat[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int strStr(char * haystack, char * needle){
    int slen;
    int plen;
    int *next;
    int i, j;
    int retval = -1;

    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    slen = strlen(haystack);
    plen = strlen(needle);
    if (plen == 0) {
        return 0;
    }  
    next = (int*)malloc(sizeof(int) * (plen + 1));
    getNext(needle, next); 
    i = 0;
    j = 0;
    while (i < slen && j < plen) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == plen) {
        retval = i - j;
    }
    free(next);
    return retval;
}


// @lc code=end

