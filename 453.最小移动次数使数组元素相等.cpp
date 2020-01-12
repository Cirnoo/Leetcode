/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 */

#include<stdc++>

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = *min_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0,[=](int a, int b)
        {
            return a+b-min_num;
        });
        return sum;
    }
   
};
// @lc code=end

