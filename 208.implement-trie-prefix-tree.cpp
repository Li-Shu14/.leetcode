/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
照抄leetcode官方答案
15/15 cases passed (76 ms)
Your runtime beats 71.08 % of cpp submissions
Your memory usage beats 56.67 % of cpp submissions (44 MB)
 */

// @lc code=start
class Trie {
private:
	bool is_string = false;
	Trie* next[26] = { NULL };
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == NULL) root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == NULL) return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == NULL)return false;
			root = root->next[p - 'a'];
		}
		return true; // 这里和search()唯一的区别
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

