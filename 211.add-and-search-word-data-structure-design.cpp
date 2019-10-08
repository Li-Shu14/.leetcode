/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        fill(child,child+26,nullptr);
        isWord = false;
    }
    ~TrieNode() {
        for (int i = 0;i<26;++i) {
            delete child[i];
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int i = c-'a';
            if (!p->child[i]) {
                p->child[i] = new TrieNode();
            }
            p = p->child[i]; 
        }
        p->isWord = true;
    }

    void addWord2(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int i = c - 'a';
            if (!p->child[i]) 
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;    
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(word,root,0);
    }

    bool match(const string& word, TrieNode* p, int start) {
        if (!p) return false;
        if (start==word.size()) return p->isWord;
        char c = word[start];
        if (c!='.') {
            return match(word,p->child[c-'a'],start+1);
        }
        else {
            for (const auto& child : p->child) {//?
                if (match(word,child,start+1)) return true;
            }
        }
        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

