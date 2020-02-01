/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */
#include<stdc++>
// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int t1[] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int t2[] = {0,31,60,91,121,152,182,213,244,274,305,335};
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        if((y%4==0&&y%100!=0)||y%400==0){
            return t2[m-1]+d;
        }else return t1[m-1]+d;
    }
};
// @lc code=end

