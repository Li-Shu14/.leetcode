/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
方法一：递归 
39/39 cases passed (16 ms)
Your runtime beats 26.01 % of cpp submissions
Your memory usage beats 92.31 % of cpp submissions (19.2 MB)

方法二：迭代
39/39 cases passed (12 ms)
Your runtime beats 61.46 % of cpp submissions
Your memory usage beats 5.49 % of cpp submissions (22.9 MB) 是否释放内存都是这么大的

方法三：递归（一行代码解决）
39/39 cases passed (16 ms)
Your runtime beats 26.01 % of cpp submissions
Your memory usage beats 45.05 % of cpp submissions (19.6 MB)
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/cyi-xing-4ms-by-xia-gu-zhen-zhen/
 */
#include <queue>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    int maxDepth1(TreeNode* root) {
        int max_dep = 0;
        if (root==NULL) return max_dep;
        helper(root,max_dep,1);
        return max_dep;
    }

    void helper(TreeNode* root, int& max_dep, int cur_dep) {
        if (cur_dep > max_dep) max_dep = cur_dep;
        if (root->left != NULL)  helper(root->left,max_dep,cur_dep+1);
        if (root->right != NULL) helper(root->right,max_dep,cur_dep+1);
    }

    int maxDepth2(TreeNode* root) {
        int max_dep = 0;
        if (root==NULL) return max_dep;
        queue<TreeNode*>* cur_layer = new queue<TreeNode*>;
        queue<TreeNode*>* next_layer= new queue<TreeNode*>;
        cur_layer->push(root);
        while(1) {
            max_dep++;
            while(!cur_layer->empty()) {
                TreeNode* temp = cur_layer->front();cur_layer->pop();
                if (temp->left != NULL) next_layer->push(temp->left);
                if (temp->right!= NULL) next_layer->push(temp->right);
            }
            if (!next_layer->empty()) {
                // delete[] cur_layer; //这种方法释放内存是有问题heap-buffer-overflow。为什么?
                *cur_layer = queue<TreeNode*>(); // 本来想着释放内存，但是有这句话内存占用为22.9MB，没有则为21.1MB，反而变大了。为什么？
                // while(!cur_layer->empty()) cur_layer->pop(); //用这种方式释放内存，结果内存占用为21.1MB，和不加一样
                cur_layer = next_layer;
                next_layer = new queue<TreeNode*>;
            }
            else break;
        }
        return max_dep;
    }

    int maxDepth3(TreeNode* root) {
        return (root==NULL)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    int maxDepth(TreeNode* root) {
        return maxDepth3(root);
    }

};
// @lc code=end

