/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
方法一：递归（同方法二）
31/31 cases passed (24 ms)
Your runtime beats 35.26 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (14.1 MB)
O(n),O(n).n次递归的栈空间。
方法讲解
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/c-jing-dian-di-gui-si-lu-fei-chang-hao-li-jie-shi-/
方法二：父指针迭代
31/31 cases passed (52 ms)
Your runtime beats 6.32 % of cpp submissions
Your memory usage beats 30.91 % of cpp submissions (17.5 MB)
迭代就是累啊。用到了stack, unordered_map, set.

方法三：无父指针的迭代
该方法来源于leetcode-cn解答，更加累。不讨论了。
 */
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* left  = lowestCommonAncestor1(root->left,p,q);
        TreeNode* right = lowestCommonAncestor1(root->right,p,q);
        if (left == NULL && right !=NULL) return right;
        if (left !=NULL && right == NULL) return left;
        if (left == NULL && right ==NULL) return NULL;
        return root;
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
            
        TreeNode* left =  lowestCommonAncestor2(root->left, p, q);
        TreeNode* right = lowestCommonAncestor2(root->right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;      
        if(left && right) return root; // p和q在两侧
        return NULL; // 必须有返回值
    }

    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent.insert({root,NULL});
        stack<TreeNode*> s;
        s.push(root);
        while (parent.find(p)==parent.end() || parent.find(q)==parent.end()) {
            TreeNode* node = s.top();s.pop();
            // While traversing the tree, keep saving the parent pointers.
            if (node->left != NULL) {
                parent.insert({node->left, node});
                s.push(node->left);
            }
            if (node->right != NULL) {
                parent.insert({node->right, node});
                s.push(node->right);
            }
        }
        set<TreeNode*> ancestors; // Ancestors set() for node p.

        // Process all ancestors for node p using parent pointers.
        while (p != NULL) {
            ancestors.insert(p);
            p = parent.at(p);
        }

        // The first ancestor of q which appears in
        // p's ancestor set() is their lowest common ancestor.
        while (ancestors.find(q)==ancestors.end()) q = parent.at(q);
        return q;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestor3(root,p,q);
    }

};
// @lc code=end

