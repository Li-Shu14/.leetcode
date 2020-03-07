/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

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
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
        vector<int> res;
        inordertraverse(root,res);
        for (int i =0;i<res.size()-1;++i) {
            if (res[i]>=res[i+1]) return false;
        }
        return true;
    }


    void inordertraverse(TreeNode* root, vector<int>& res){
        if (root->left!=NULL) inordertraverse(root->left,res);
        res.push_back(root->val);
        if (root->right!=NULL) inordertraverse(root->right,res);
    }

};
// @lc code=end

