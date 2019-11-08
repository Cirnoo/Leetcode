import java.util.Arrays;
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=459 lang=java
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
    boolean check(String str, int index){
        String p = str.substring(0, index);
        if(str.length()%index!=0){
            return false;
        }
        for(int i=index;i<=str.length();i+=index){
            // System.out.println(str.substring(i-index,i));
            // System.out.println(p);
            if(!str.substring(i-index,i).equals(p)){
                return false;
            }
        }
        return true;
    }
    public boolean repeatedSubstringPattern(String s) {
        for(int i=1;i<=s.length()/2;++i){
            if(check(s, i)){
                return true;
            }
        }
        return false;
    }
}
// @lc code=end

