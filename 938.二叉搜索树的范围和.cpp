/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */
#include<stdc++>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        int ans = 0;
        if(root->val>=L && root->val<=R)
        {
            ans += root->val; 
        }
        return ans+rangeSumBST(root->left,L,R) + rangeSumBST(root->right, L, R);
    }

};
// @lc code=end

