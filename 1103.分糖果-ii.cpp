/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */
#include<stdc++>
// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int cur_num = 1;
        int index = 0;
        while(candies>0)
        {
            if(cur_num>candies)
            {
                cur_num = candies;
            }
            ans[index%num_people] += cur_num;
            candies-=cur_num;
            ++cur_num;
            index++;
        }
        return ans;
    }
};
// @lc code=end

