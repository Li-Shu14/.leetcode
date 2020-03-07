/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal


203/203 cases passed (16 ms)
Your runtime beats 83.75 % of cpp submissions
Your memory usage beats 14.29 % of cpp submissions (22.1 MB)
 */
// @lc code=start
#include <vector>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) return NULL;
        return helper(preorder,inorder,0,preorder.size(),0,inorder.size());
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int p1, int p2, int i1, int i2){
        // p2, i2 是哨兵，实际上取不到的右边界
        TreeNode* root = new TreeNode(preorder[p1]);
        vector<int>::iterator ite1 = find(inorder.begin()+i1, inorder.begin()+i2, preorder[p1]);
        int index  = ite1 - inorder.begin();
        int length = index - i1;
        if (index != i1) root->left = helper(preorder,inorder,p1+1,p1+length+1,i1,index); // 有左子树
        if (index != i2-1) root->right= helper(preorder,inorder,p1+length+1,p2,index+1,i2); // 有右子树
        return root;
    }
};  
// @lc code=end

