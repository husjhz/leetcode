/*
 * @lc app=leetcode.cn id=820 lang=c
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (49.35%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    45.6K
 * Total Submissions: 91.5K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 * 
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes =
 * [0, 2, 5]。
 * 
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 * 
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 * 
 * 
 */

// @lc code=start

static int comp(const void *a, const void *b)
{
    return strcmp(*(char **)a,  *(char **)b) > 0;
}

static void reserve(char *s, int size)
{
    int i = 0;
    int j = size - 1;

    while (i < j) {
        char tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }
}

static int substring(char *a, char *b)
{
    while (*a != '\0' && *b != '\0') {
        if (*a++ != *b++) {
            return 0;
        }
    }
    return 1;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int i;
    int result = 0;

    if (wordsSize == 1) {
        return strlen(words[0]) + 1;
    }
    for (i = 0; i < wordsSize; i++) {
        reserve(words[i], strlen(words[i]));
    }
    qsort(words, wordsSize, sizeof(char **), comp);
    for (i = 0; i < wordsSize - 1; i++) {
        if(substring(words[i], words[i + 1]) == 0) {
            result += strlen(words[i]);
            result++;
        }
    }
    return result + strlen(words[i]) + 1;
}
// @lc code=end
