/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 

 方法一：转换成中序遍历得到的数组，看数组是否对称。
 这个方法通过为：192/195. 错误案例：[1,2,2,2,null,2]

 方法二：转换成先序和后序的两个数组，比较俩数组是否互为逆序。
 这个方法通过为：141/195。错误案例：[1,2,2,null,3,null,3]

 方法三：将上述俩方法结合起来一同判断。
 这个方法通过为：194/195。错误案例：[1,2,2,2,null,2]

 方法四：设计一个SymInorder的函数，来与Inorder函数做对应。
 失败案例同方法一。

 不要再投机取巧了！！！试图转换成数组的方法并不符合树结构的思想。

方法五：递归（来自leetcode官网）
195/195 cases passed (12 ms)
Your runtime beats 10.13 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (14.6 MB)

方法六：迭代（来自leetcode官网）
195/195 cases passed (4 ms)
Your runtime beats 85.32 % of cpp submissions
Your memory usage beats 32.2 % of cpp submissions (15.1 MB)


 */

// @lc code=start

class Solution {
public:

    bool isSymmetric5(TreeNode* root) {
    return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val)
        && isMirror(t1->right, t2->left)
        && isMirror(t1->left, t2->right);
    }

    bool isSymmetric6(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* t1 = q.front();q.pop();
            TreeNode* t2 = q.front();q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
}

    bool isSymmetric(TreeNode* root) {
        return isSymmetric6(root); 
    }

    //----------wrong answers------------

    bool isSymmetric1(TreeNode* root) {
        if (root==NULL) return true;
        vector<int> res;
        inorder(root,res);
        if (res.size()%2==0) return false;
        for (int i=0;i<res.size()/2;++i){
            if (res[i] != res[res.size()-i-1]) return false;
        }
        return true;
    }

    bool isSymmetric2(TreeNode* root) {
        if (root==NULL) return true;
        vector<int> pre;
        vector<int> post;
        preorder(root,pre);
        postorder(root,post);
        if (pre.size()%2==0) return false;

        for (int i=0;i<pre.size();++i){
            if (pre[i] != post[post.size()-i-1]) return false;
        }
        return true;
    }

    bool isSymmetric3(TreeNode* root) {
        return isSymmetric1(root) && isSymmetric2(root);
    }

    bool isSymmetric4(TreeNode* root) {
        if (root==NULL) return true;
        vector<int> res;
        inorder(root,res);
        vector<int> symres;
        syminorder(root,symres);
        if (res.size()%2==0) return false;

        for (int i=0;i<res.size();++i){
            cout<<res[i]<<','<<symres[i]<<endl;
        }
        for (int i=0;i<res.size();++i){
            if (res[i] != symres[i]) return false;
        }
        
        return true;
    }


    void inorder(TreeNode* root, vector<int>& res) {
        // if (root==NULL) return;
        if (root==NULL) {res.push_back(-1); return;}
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    void preorder(TreeNode* root, vector<int>& res) {
        if (root==NULL) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    void postorder(TreeNode* root, vector<int>& res) {
        if (root==NULL) return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }

    void syminorder(TreeNode* root, vector<int>& res) {
        // if (root==NULL) return;
        if (root==NULL) {res.push_back(-1); return;}
        syminorder(root->right,res);
        res.push_back(root->val);
        syminorder(root->left,res);
    }
};
// @lc code=end

