/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
方法一：
构建了两个记忆map来降低递归的重复计算。
但是不够美。而且答案还是错的。。。

方法二：来自labuladong
只需要一个记忆map就好了。这个map只需要记录选择抢劫当前节点后所能得到的最大收益即可。
执行用时 :
32 ms, 在所有 C++ 提交中击败了59.48%的用户
内存消耗 :
25.3 MB, 在所有 C++ 提交中击败了5.88%的用户

方法三：来自labuladong
执行用时 :
28 ms, 在所有 C++ 提交中击败了69.01%的用户
内存消耗 :
32.5 MB, 在所有 C++ 提交中击败了5.88%的用户

动规的优化。其实甚至不需要记忆map。因为自始至终所关注的不过是每个节点的两个量————抢劫该节点的值和不抢该节点的值。

方法四：将方法三中的vector换成了int数组。
执行用时 :
28 ms, 在所有 C++ 提交中击败了69.01%的用户
内存消耗 :
27.5 MB, 在所有 C++ 提交中击败了5.88%的用户

可见将vector替换为数组也没太节约空间···
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int rob1(TreeNode* root) {
        vector<unordered_map<TreeNode* ,int>> mem {unordered_map<TreeNode* ,int> mem0, unordered_map<TreeNode* ,int> mem1};
        //unordered_map<TreeNode* ,int> mem1; // include current node
        //unordered_map<TreeNode* ,int> mem0; // not include current node
        return max(recursive_search(root, mem, 1),recursive_search(root,mem, 0));
    }

    int recursive_search(TreeNode* root, vector<unordered_map<TreeNode* ,int>>& mem, int flag){
        if (!root) return 0;
        
        // include root node
        if (mem[flag].find(root) != mem[flag].end()) return mem[flag][root];
        else {
            if (flag == 0) {
                int left = max(recursive_search(root->left,mem,0),recursive_search(root->left,mem,1));
                int right = max(recursive_search(root->right,mem,0),recursive_search(root->right,mem,1));
                mem[flag][root] = left + right;
            }
            else {
                mem[flag][root] = recursive_search(root->left,mem,0) + recursive_search(root->right,mem,0) + root->val;
            return mem[flag][root];
            }
            
        }
        return 0;
    }

    //-------------
    unordered_map<TreeNode*, int> memo;
    int rob2(TreeNode* root) {
        if (!root) return 0;

        if (memo.find(root)!=memo.end())  // 利用备忘录消除重叠子问题
            return memo[root];
        // 抢，然后去下下家
        int do_it = root->val
            + (root->left == NULL ? 
                0 : rob2(root->left->left) + rob2(root->left->right))
            + (root->right == NULL ? 
                0 : rob2(root->right->left) + rob2(root->right->right));
        // 不抢，然后去下家
        int not_do = rob2(root->left) + rob2(root->right);
        int res = max(do_it, not_do);
        memo[root] =  res;
        return res;
    }

    int rob3(TreeNode* root) {
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }

    vector<int> dp(TreeNode* root) {
        /* 返回一个大小为 2 的数组 arr
        arr[0] 表示不抢 root 的话，得到的最大钱数
        arr[1] 表示抢 root 的话，得到的最大钱数 */
        if (root == NULL)
            return vector<int> {0, 0};
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        // 抢，下家就不能抢了
        int rob = root->val + left[0] + right[0];
        // 不抢，下家可抢可不抢，取决于收益大小
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int> {not_rob, rob};
    }

    int rob4(TreeNode* root) {
        int* res = dp2(root);
        return max(res[0], res[1]);
    }

    int* dp2(TreeNode* root) {
        if (root == NULL)
            return new int[2] {0, 0};
        int* left = dp2(root->left);
        int* right = dp2(root->right);
        // 抢，下家就不能抢了
        int rob = root->val + left[0] + right[0];
        // 不抢，下家可抢可不抢，取决于收益大小
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return new int[2] {not_rob, rob};
    }

    int rob(TreeNode* root) {
        return rob4(root);
    }
};
// @lc code=end

