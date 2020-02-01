/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

#include<stdc++>
// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int t = arr.size()/4;
        for(int i=0;i<arr.size()-t;++i)
        {
            if(arr[i]==arr[i+t])
            {
                return arr[i];
            }
        }
        return 0;
    }
};
// @lc code=end

