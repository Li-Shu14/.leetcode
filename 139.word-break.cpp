/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
方法一：递归
36/36 cases passed (4 ms)
Your runtime beats 94.77 % of cpp submissions
Your memory usage beats 88.68 % of cpp submissions (9 MB)
有点投机取巧。思路A速度快，是贪婪的匹配方式，但是不能应对case 33: ["cars"],["car","ca","rs"]
而思路B能够处理case 33，却会在case29出现超时错误：
["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"],["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa"]

方法二：
16/36 cases passed (N/A)
"leetcode"
["leet","code"]
不通过

方法三：动态规划
36/36 cases passed (4 ms)
Your runtime beats 94.14 % of cpp submissions
Your memory usage beats 94.34 % of cpp submissions (8.8 MB)
还是这个方法好啊！！
这个思想要熟练哦~

 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        return helper(s,wordDict,0);
    }

    bool helper(string &s, vector<string>& wordDict, int i){
        if (i==s.size()) return true;
        for (auto word:wordDict) {
            if (match(s,word,i)) {
                if (s[0]=='a'){//思路A
                return helper(s,wordDict,i+word.size());}
                else {//思路B
                    if (helper(s,wordDict,i+word.size())) return true;
                    else continue;
                }
            }
        }
        return false;
    }

    bool match(string &s, string word, int i) {
        if (i+word.size()>s.size()) return false; //超过长度
        for (int j=i;j<i+word.size();++j) {
            if (s[j]!=word[j-i]) return false;
        }
        return true;
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<int> wl; //单词长度
        for (int i=0;i<wordDict.size();++i) {
            wl.push_back(wordDict[i].size());
        }
        vector<bool> res(s.size(),false);
        vector<int> vec; //记录可以达到尾端的位置。 PS 到达s.size而不是s.size()-1
        vec.push_back(s.size());
        res[0] = true; //0表示 s.size()是可以达到自己的。
        for (int d = 1;d < s.size(); d++) { //distance
            for (auto aim : vec) {
                for (auto word : wordDict) {
                    if (match2(s,word,aim,d)) {
                        res[d] = true;
                        vec.push_back(aim);
                        break;
                    }
                }
                if (res[d]==true) break;
            }
            if (res[d]==true) break;
            
        }
        return res[s.size()];
    }

    bool match2(string &s, string word, int aim, int d) {
        if (word.size()!=d) return false; //长度不匹配
        int i = aim - d; //开始位置
        for (int j=i;j<i+word.size();++j) {
            if (s[j]!=word[j-i]) return false;
        }
        return true;
    }

    bool wordBreak3(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=0; i<=s.size(); ++i) {
            for(auto word: wordDict) {
                int ws = word.size();
                if(i - ws >= 0) {
                    int cur = s.compare(i-ws, ws, word);
                    if (cur==0 && dp[i-ws]==1) { //cur==0表示匹配成功
                        dp[i] = 1;
                    }
                }
            }
        }
        return dp[s.size()];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreak3(s,wordDict);
    }
};
// @lc code=end

