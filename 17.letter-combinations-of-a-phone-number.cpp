/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
/*
25/25 cases passed (4 ms)
Your runtime beats 59.73 % of cpp submissions
法一：Your memory usage beats 80 % of cpp submissions (8.6 MB)
法二：Your memory usage beats 91.43 % of cpp submissions (8.5 MB)
两种方法均来自于leetcode。递归法。本题可以学习的点：
1. 返回空的vector时可以直接用return {}
2. 快速构造unordered_map的方法（其实和快速构造vector<vector<int>>是一样的，用两层花括号。（这个特性只有c++11之后才有）
3. for循环字符串迭代器： for (char c : string) {}
4. 思路上的不同，前者只使用了一个固定的combination,地址传递。在递归的时候用了复制传递combination，从空间上讲浪费了。
5. 灵活运用两个字符相减得到整型的用法。

方法三：
25/25 cases passed (4 ms)
Your runtime beats 59.73 % of cpp submissions
Your memory usage beats 75.71 % of cpp submissions (8.7 MB)
参考了https://blog.csdn.net/RaKiRaKiRa/article/details/82941290  的做法。他的map生成过程太丑了。方法应该叫做“生长法”，用三层循环取代了递归。
*/

vector<string> letterCombinations1(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> num_to_char {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> result; 
        string combination(digits.length(), ' ');
        letterCombinations(digits, combination, 0, num_to_char, result);
        return result;
    }
void letterCombinations(string digits, string& combination, int idx,  unordered_map<char, string>& num_to_char, vector<string>& result) {
        if (idx == digits.length()){
            result.push_back(combination);
            return;
        }
        
        for (char c : num_to_char[digits[idx]]){
            combination[idx] = c;
            letterCombinations(digits, combination, idx + 1, num_to_char, result);
        }
    } 
vector<string> letterCombinations2(string digits) {
    if (digits=="") return {};
    unordered_map<int,string> dic {{1,"abc"},{2,"def"},{3,"ghi"},{4,"jkl"},{5,"mno"},{6,"pqrs"},{7,"tuv"},{8,"wxyz"}};
    string combination;
    vector<string> ret;
    combinations(digits,combination,0,dic,ret);
    return ret;
}

void combinations(string& digits,string combination,int idx,unordered_map<int,string>& dic, vector<string>& ret){
    if (idx==digits.length()) {
        ret.push_back(combination);
        return;
    }
    for (char c : dic[digits[idx]-'1']) {
        combinations(digits,combination+c,idx+1,dic,ret);
    }
}

vector<string> letterCombinations3(string digits) {
int sz = digits.size(), tvsz;
	if (sz == 0) return vector<string>(); //或者 {}
	unordered_map<char, string> dic {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}; 
	string ts,tv;
    vector<string> res, tres;
	res.push_back("");
	for (int i = 0; i < sz; ++i) {
		int ressz = res.size();
		tres.clear();
		tv = dic[digits[i]];
		tvsz = tv.length();
		for (int j = 0; j < ressz; ++j) {
			ts = res[j];
			for (char c:tv) {
				tres.push_back(ts + c);
			}
		}
		res = tres;
	}
	return res;
}

vector<string> letterCombinations(string digits) {
    return letterCombinations3(digits);
}
};

// @lc code=end

