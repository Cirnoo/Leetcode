/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

#include<stdc++>
// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string t,ans;
        for(char c:S)
        {
            if(c!='-')
            {
                t+=toupper(c);
            }
        }
        if(t.size()<=K)
        {
            return t;
        }
        int cnt = (t.size()-1)/K;
        int cur = t.size()-1;
        for(int i=0;i<cnt;++i)
        {
            t+=' ';
        }
        for(int i=t.size()-1,cnt = 0;i>=0;--i)
        {
            if(cnt == K)
            {
                t[i]='-';
                cnt = 0;
            }
            else
            {
                t[i]=t[cur--];
                ++cnt;
            }
        }
        return t;
    }
};
// @lc code=end

