/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 */
#include<stdc++>
// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int ans_index;
        int size = INT_MAX;
        array<int,26> buf={0};
        int cnt = 0;
        for(char c:licensePlate)
        {
            if(isalpha(c))
            {
                ++buf[(tolower(c)-'a')];
                ++cnt;
            }
        }
        int index = 0;
        for(const string & str : words)
        {
            if(str.size()<size && checkStr(str,buf, cnt))
            {
                ans_index = index;
                size = str.size();
            }
            ++index;
        }
        return words.at(ans_index);
    }

    bool checkStr(const string & str, array<int,26> buf, int cnt)
    {
        for(char c : str)
        {
            if(buf[c-'a']>0)
            {            
                --buf[c-'a'];
                --cnt;
            }
        }
        return cnt==0;
    }
};
// @lc code=end

