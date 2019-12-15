/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
#include <set>
using namespace std;
/*
方法一：
简单地认为generateParenthesis(n) = {()+generateParenthesis(n-1)} + { ( + generateParenthesis + ) } + { generateParenthesis(n-1) + () }
然后再去重即可。但是对于n=4的下面这个例子就无法生成了。
"(())(())"
这个方法走不通。但是利用vector->set->vector的去重技巧可以记住。
这是我在百度实习二面遇到的题，当时用这个方法把面试官糊弄过去了···但其实没这么简单

方法二： 暴力搜搜 O(n*4^n)
方法三： 回溯法 backtracking  O(4^n / sqrt(n))  （来源于leetcode官网）
    Runtime: 8 ms, faster than 54.26% of C++ online submissions for Generate Parentheses.
    Memory Usage: 17.2 MB, less than 74.38% of C++ online submissions for Generate Parentheses.
方法四：闭合数 Closure Number O(4^n / sqrt(n))  （来源于leetcode官网）
    Runtime: 12 ms, faster than 18.41% of C++ online submissions for Generate Parentheses.
    Memory Usage: 15.5 MB, less than 78.51% of C++ online submissions for Generate Parentheses.
    这个方法是真的牛！
    核心思路请见官网。
*/
class Solution {
public:
    vector<string> generateParenthesis1(int n) {
        if (n==0) return {};
        if (n==1) return {"()"};
        vector<string> last = generateParenthesis(n-1);
        vector<string> vec;
        for (string s : last) {
            vec.push_back("()"+s);
            vec.push_back("("+s+")"); 
            vec.push_back(s+"()");
        }
        set<string> se(vec.begin(), vec.end());
        vec.assign(se.begin(), se.end());
        return vec;
    }
//-----------------------------------
    // vector<string> generateParenthesis2(int n) {
    // }

//-----------------------------------
    vector<string> generateParenthesis3(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
    void backtrack(vector<string> res, string cur, int open, int close, int max) {
        if (cur.length() == max * 2) {
            res.push_back(cur);
            return;
        }
        if (open < max) backtrack(res,cur+"(",open+1,close,max);
        if (close < open) backtrack(res,cur+")",open,close+1,max);
    }
//-----------------------------------
    vector<string> generateParenthesis4(int n) {
        vector<string> res;
        if (n==0) {
            res.push_back("");
        }
        else {
            for (int c = 0; c < n; ++c) {
                for (string left:generateParenthesis4(c)){
                    for (string right:generateParenthesis4(n-1-c)) {
                        res.push_back("("+left+")"+right);
                    }
                }
            } 
        }
        return res;
    }
//-----------------------------------
    vector<string> generateParenthesis(int n) {
        return generateParenthesis4(n);
    }
};


