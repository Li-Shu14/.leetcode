/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
 34/34 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 15.49 % of cpp submissions (14.9 MB)
参考leetcode官方做法：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-ci-bian-li-by-leetcode/

方法二：迭代
34/34 cases passed (4 ms)
Your runtime beats 94.1 % of cpp submissions
Your memory usage beats 98.59 % of cpp submissions (13.7 MB)
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/bfsdie-dai-di-gui-by-24shi-01fen-_00_01/

方法三：
层次遍历常用的两个模板（1）
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-ceng-ci-bian-li-liang-ge-chang-yong-mo-/
这个迭代的代码本质思想和方法二完全一致，但是非常简洁。推荐。

 */
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    vector<vector<int>> levels; //当然这个变量也可以放进函数里，引用传递。
    void helper(TreeNode* root, int level) {
        if (levels.size() == level) levels.push_back({}); //start the current level
        levels[level].push_back(root->val); // append the current node value
        if (root->left!=NULL)  helper(root->left, level+1);
        if (root->right!=NULL) helper(root->right,level+1);

    }
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root==NULL) return levels;
        helper(root, 0);
        return levels;
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        vector<int> level_res;
        int curNums=1, nextNums=0;
        queue<TreeNode*> queue;
        TreeNode* node;
        queue.push(root);
        while(!queue.empty()){
            node = queue.front(); //最先进入的元素（和pop指的是同一个）
            level_res.emplace_back(node->val);
            queue.pop();
            curNums--;
            if(node->left!=NULL){
                queue.push(node->left);
                nextNums++;
            }     
            if(node->right!=NULL){
                queue.push(node->right);
                nextNums++;
            }
            if(curNums == 0){
                res.emplace_back(level_res); 
                level_res.clear(); //这里用clear，也可以每次在循环内新建一个level_res
                curNums = nextNums;
                nextNums = 0;
            }    
        }
        return res; 
    }

    vector<vector<int>> levelOrder3(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level_res;
            int siz = q.size();  // 记录当前层有多少个节点
            for (int i = 0; i < siz; i++) {  // 让当前层的节点出队， 把下一层的节点放入队列中
                auto t = q.front(); q.pop();
                level_res.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(level_res);
        }  
        return res;
    }

    vector<vector<int>> levelOrder4(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            TreeNode *p = t.first;
            int level = t.second;
            // 把下一层新建出来  res.size() - 1 < level。 要写成 (int)res.size() - 1 < level
            if (res.size() < level + 1)  res.push_back(vector<int>());
            
            res[level].push_back(p->val);
            if (p->left) q.push({p->left, level + 1});
            if (p->right) q.push({p->right, level + 1});
        }
        
        return res;
    }

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrder4(root);
    }
};
// @lc code=end

