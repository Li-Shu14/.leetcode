/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
方法一：先序遍历后再逐一连接。
225/225 cases passed (8 ms)
Your runtime beats 68.43 % of cpp submissions
Your memory usage beats 8.33 % of cpp submissions (12 MB)
注意在最后返回的root应该是链表的最后一个元素而不是第一个元素。

方法二：真正的inplace算法。不需要额外的空间。（参考自leetcode)
225/225 cases passed (12 ms)
Your runtime beats 26.44 % of cpp submissions
Your memory usage beats 8.33 % of cpp submissions (11.3 MB)

方法三：先序遍历后再逐一连接（参考自leetcode,但本质上同方法一)
225/225 cases passed (8 ms)
Your runtime beats 68.43 % of cpp submissions
Your memory usage beats 8.33 % of cpp submissions (12 MB)

 */
class Solution {
public:
    void flatten1(TreeNode* root) {
        if (root==NULL) return;
        queue<int> q;
        preorder(root,q);
        root = new TreeNode(q.front()+1);
        TreeNode* cur = root;
        q.pop();
        while(!q.empty()){
            TreeNode* node = new TreeNode(q.front());
            q.pop();
            cur->right = node;
            cur = node;
        }
        root = cur;
        return;
    }

    void preorder(TreeNode* root,queue<int>& q) {
        q.push(root->val);
        if (root->left!=NULL) preorder(root->left,q);
        if (root->right!=NULL)preorder(root->right,q);
    }

    void flatten2(TreeNode* root) {
        while (root != NULL) {
            if (root->left != NULL) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != NULL) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                root->left = NULL; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        return;
    }

    vector<TreeNode*> m_nodes;
	void preOrder(TreeNode* root) {
		if(!root) return;
		m_nodes.push_back(root);
		preOrder(root->left);
		preOrder(root->right);
	}
    void flatten3(TreeNode* root) {
    	if(!root) return;
    	preOrder(root); // push the sorted nodes into vector<TreeNode*> m_nodes
    	root->left = NULL;
    	for(size_t i=1;i<m_nodes.size();++i){
    		TreeNode* new_node = new TreeNode(m_nodes[i]->val);
    		root->right = new_node;
    		root = root->right;
    	}
    }

    void flatten(TreeNode* root) {
        flatten2(root);
        return;
    }


};
// @lc code=end

