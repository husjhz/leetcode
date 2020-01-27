/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.25%)
 * Likes:    1339
 * Dislikes: 0
 * Total Accepted:    189.2K
 * Total Submissions: 466.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start

bool isValid(char * s){
    char *stack;
    int top = -1;
    int len = strlen(s);
    char *tmp = s;

    if (len == 0) {
        return true;
    }
    stack = (char*)malloc(sizeof(char) * len);
    while (*tmp != '\0') {
        if (*tmp == '{' || *tmp == '[' || *tmp == '(') {
            stack[++top] = *tmp;
        }
        else if (top >= 0) {
            if ((*tmp == '}' && stack[top] == '{') || (*tmp == ']' && stack[top] == '[') || 
                (*tmp == ')' && stack[top] == '(')) {
                --top;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
        tmp++;
    }
    return top == -1;
}


// @lc code=end

