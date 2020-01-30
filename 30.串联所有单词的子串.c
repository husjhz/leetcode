/*
 * @lc app=leetcode.cn id=30 lang=c
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (28.35%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 74K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findInWords(char * s, char ** words, int wordsSize, int wordLen, int * wordFlags)
{
    int i;

    for (i = 0; i < wordsSize; i++) {
        if (wordFlags[i] == 1) {
            continue;
        }
        if (strncmp(s, words[i], wordLen) == 0) {
            wordFlags[i] = 1;
            return 1;
        }
    }
    return 0;
}

int checkWordFlags(int *wordFlags, int wordsSize)
{
    int i;

    for (i = 0; i < wordsSize; i++) {
        if (wordFlags[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int i, j;
    int *wordFlags;
    int wordLen;
    int sLen;
    int *returnArray;

    *returnSize = 0;
    if (s == NULL || strlen(s) == 0 || words == NULL || wordsSize == 0) {
        return NULL;
    }
    wordFlags = (int*)malloc(sizeof(int) * wordsSize);
    memset(wordFlags, 0, sizeof(int) * wordsSize);
    wordLen = strlen(words[0]);
    sLen = strlen(s);
    returnArray = (int*)malloc(sizeof(int) * sLen);
    for (i = 0; i <= sLen - wordsSize * wordLen; i++) {
        for (j = i; j <= sLen - wordLen; j += wordLen) {
            if (findInWords(s + j, words, wordsSize, wordLen, wordFlags) == 0) {
                break;
            }
        }
        if (checkWordFlags(wordFlags, wordsSize) == 1) {
            returnArray[*returnSize] = i;
            (*returnSize)++;
        }
        memset(wordFlags, 0, sizeof(int) * wordsSize);
    }
    free(wordFlags);
    return returnArray;
}


// @lc code=end

