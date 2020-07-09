/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
/*
  ✔ Your runtime beats 85.48 % of cpp submissions
  ✔ Your memory usage beats 72.41 % of cpp submissions (8.9 MB)
  此方法比较狼狈，对于奇数和偶数回文序列是分开讨论的.
  1.看到leetcode管网给出的解法4也是如此，“中心扩张法”，但他机智地将重复部分写成了函数，很漂亮
  2.此外，基于动态规划方法也不错。（考虑如何将空间复杂度从o(n2)降低）。
  3.基于LCS的动态规划时间复杂度总是o(n2)，这个背下来后可以直接套用。
*/
        if (s=="") return "";
        int max_len=1,len=1,offset=1,h=0;
        int str_len = s.size();
        for (int i=0;i<s.size();++i) {
            while((i-offset) > -1 and (i+offset) < str_len) {
                if (s[i-offset] == s[i+offset]) {
                    len += 2;
                    if (len > max_len) {
                        h = i-offset;
                        max_len = len;
                    }
                    offset++;
                } 
                else {
                    break;
                }
            }
            len = 1;
            offset = 1;
        }
        offset = 1;
        len = 1;
        for (int i=0;i<s.size()-1;++i) {
            if (s[i]==s[i+1]) {
                len = 2;
                if (len > max_len) {
                    h = i;
                    max_len = len;
                }
                while((i-offset) > -1 and (i+offset+1) < str_len) {
                    if (s[i-offset] == s[i+offset+1]) {
                        len += 2;
                        if (len > max_len) {
                            h = i-offset;
                            max_len = len;
                        }
                        offset++;
                    }
                    else {
                        break;
                    }
                } 
            len = 1;
            offset = 1;
            }
        }
        string res = s.substr(h,max_len);
        return res;
    }

    /*方法二：
    manacher算法
    */
    


};

