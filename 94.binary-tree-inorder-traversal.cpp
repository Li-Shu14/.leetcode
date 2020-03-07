/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
 * 
方法一：递归
68/68 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 64 % of cpp submissions (9.3 MB)
res.push_back(root->val) 放在 前、中、后 分别就是先序、中序、后序遍历···
方法二：迭代
68/68 cases passed (8 ms)
Your runtime beats 6 % of cpp submissions
Your memory usage beats 99 % of cpp submissions (8.9 MB)
补充：各种方法讲解：
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/
讲了先中后序遍历的迭代写法。很棒。

各序遍历的说明：
https://www.jianshu.com/p/acb33735b933

 */
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
class Solution {
public:
    // struct TreeNode {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // };
    vector<int> inorderTraversal2(TreeNode* root) {
        if (root==NULL) return {};
        vector<int> res;
        inordertraverse(root,res);
        return res;
    }

    void inordertraverse(TreeNode* root, vector<int>& res){
        if (root->left!=NULL) inordertraverse(root->left,res);
        res.push_back(root->val);
        if (root->right!=NULL) inordertraverse(root->right,res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            rt=S.top();S.pop();  
            v.push_back(rt->val);
            rt = rt->right;
        }
        return v;        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        return inorderTraversal1(root);
    }

    // other codes: 先序遍历， 后序遍历的递归和迭代写法
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
        return v;        
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // 此方法和preorderTraversal很像（顺序相反），最后多一个逆序。其余一致。
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt=rt->right;
            }
            rt=S.top();S.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        stack<TreeNode*> S;
        unordered_map<TreeNode*,int> done;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            while(S.size() && done[S.top()]){ //这一步太美了。注意while
                v.push_back(S.top()->val);
                S.pop();
            }
            if(S.size()){
                rt=S.top()->right;
                done[S.top()]=1;    
            }
        }
        return v;
    }



};
// @lc code=end

