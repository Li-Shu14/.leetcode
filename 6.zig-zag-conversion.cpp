/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert1(string s, int numRows) {
/*
  ✔ Your runtime beats 29.23 % of cpp submissions
  ✔ Your memory usage beats 27.78 % of cpp submissions (13.1 MB)
*/
        if (s=="" or numRows==1) return s;
        string* strs[numRows];
        int T = numRows*2 - 2;
        for (int i=0;i<numRows;++i) {
            strs[i] = new string;
        }
        for (int i=0;i<s.size();++i) {
            *strs[index(i,numRows)] += s[i];
        }
        string final;
        for (int i=0;i<numRows;++i) {
            final += *strs[i];
        }
        return final;
    };
    
    string convert2(string s, int numRows) {
/*
  ✔ Your runtime beats 75.82 % of cpp submissions
  ✔ Your memory usage beats 33.33 % of cpp submissions (12.9 MB)
Leetcode: Approach 1: Sort by Row
*/
        if (numRows == 1) return s;
        // 这里采用string的vector比我的string的数组感觉会好一些，后面的for循环可以直接写迭代器
        vector<string> rows(min(numRows, int(s.size()))); 
        int curRow = 0;
        bool goingDown = false;
        for (char c : s) { // 这里用的很漂亮，避免采用计数器i，也就避免了取余数等麻烦的操作。
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }

        string convert3(string s, int numRows) {
/*
  ✔ Your runtime beats 75.82 % of cpp submissions
  ✔ Your memory usage beats 59.26 % of cpp submissions (10.5 MB)
  Leetcode: Approach 2: Visit by Row
  这个方法直接一排一排地考虑。周期性。
*/
        if (numRows == 1) return s;
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }

    string convert(string s, int numRows) {
        return convert3(s,numRows);
    }
private:
    int index(int i, int numRows) {
        int T = numRows*2 - 2;
        int res = i%T;
        if (res > numRows - 1) res = T - res;
        return res;
    }
};

