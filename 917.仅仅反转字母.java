/*
 * @lc app=leetcode.cn id=917 lang=java
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode-cn.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (51.63%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 11.9K
 * Testcase Example:  '"ab-cd"'
 *
 * 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 示例 2：
 * 
 * 输入："a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 示例 3：
 * 
 * 输入："Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S 中不包含 \ or "
 * 
 * 
 */

// @lc code=start
class Solution {
    boolean isAlpha(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public String reverseOnlyLetters(String S) {
        char[] str = S.toCharArray();
        int index = S.length() - 1;
        int i = 0;
        while (i < S.length() && index >= 0) {
            if (isAlpha(str[index]) && isAlpha(S.charAt(i))) {
                str[index--] = S.charAt(i++);
            } else if (!isAlpha(str[index])) {
                index--;
            } else {
                ++i;
            }
        }
        return new String(str);
    }
}
// @lc code=end
