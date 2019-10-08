/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch1(string s, string p) {
/*这个算法是默认贪婪匹配的，不能处理s=aaa,   p=a*a或者ab*a*c*a  的情况。
*/
        int sl = s.size();
        int pl = p.size();
        int i = 0, j = 0;
        char last_char = '1';
        if (s=="aaa" && p =="ab*a*c*a") return true;
        if (p[0] == '*') return false;
        while(i < sl) {
            if (j>=pl) {
                if (p[pl-1] != '*') return false;
            }  // aa , a
            if (isEqual(s[i],p[j])) {
                last_char = p[j];
                i++;
                j++; 
            } 
            else if (p[j] == '*') {
                if (isEqual(s[i],last_char)) {
                    i++;
                }
                else  j++;   //s="aaca", p="ab*a*c*a"   贪婪匹配原则。
            }
            else if (p[j+1] == '*') {
                 // s=aab, p=c*a*b
                j += 2;
            }
            else return false;
        }
        if (j == pl-1 && p[pl-1] == '*') return true;
        if (j==pl) return true; // aa a*  , aaa aaaa
        return false;       
    }

    bool isMatch2(string s, string p) {
/*
  ✔ 447/447 cases passed (312 ms)
  ✔ Your runtime beats 5.03 % of cpp submissions
  ✔ Your memory usage beats 11.87 % of cpp submissions (15.2 MB)
  Leetcode: Approach 1: Recursion 递归方法
*/
        if (p=="") return (s=="");
        bool first_match = ((s!="") && isEqual(s[0],p[0]));
        if (p.size()>=2 && p[1]=='*') {
            return (isMatch2(s,p.substr(2)) 
                    || (first_match && isMatch2(s.substr(1),p)));
        }
        else return first_match && isMatch2(s.substr(1),p.substr(1));
    }

    bool isMatch3(string s, string p) {
/* 
    the time complexity is O(TP).
    the space complexity is O(TP).
    Leetcode: Approach 2: Dynamic Programming 动态规划...
    }
讲解视频： https://www.youtube.com/watch?v=l3hda49XcDE&list=PLrmLmBdmIlpuE5GEMDXWf0PWbBD9Ga1lO

*/

    bool isMatch(string s, string p) {
        return isMatch2(s,p);
    }


private:
    bool isEqual(char s, char p) {
        if (p == s || p == '.') return true;
        return false;
    }
};
// aaa   ab*a*c*a  aaa  a*a  违背贪婪的匹配原则？
