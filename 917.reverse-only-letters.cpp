/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */
// ASIC     a-z:97-122 A-Z:65-90
// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool isletter(char c) {
        if ((64 < c && c < 91) || (96 < c && c < 123)) return true;
        return false;
    }
public:
    string reverseOnlyLetters1(string S) {
/*
116/116 cases passed (4 ms)
Your runtime beats 56.82 % of cpp submissions
Your memory usage beats 90.91 % of cpp submissions (8.2 MB)
*/
        int len = S.size();
        string ret(len,' ');
        int l = 0, r = S.size()-1;
        while(l < len) {
            if (!isletter(S[l])) {
                ret[l] = S[l];
                l++;
            }
            else {
                if (isletter(S[r])) {
                    ret[l]=S[r];
                    l++;
                    r--;
                } else {
                    r--;
                }
            }
        }
        return ret;
    }

    string reverseOnlyLetters2(string S) {
/*
116/116 cases passed (4 ms)
Your runtime beats 56.82 % of cpp submissions
Your memory usage beats 90.91 % of cpp submissions (8.3 MB)
别人写的。和我差不多，但是更简洁。
*/
        string ret = S;
        int n = S.length();
        int start = 0;
        int end = n - 1;
        while(start <= n-1 && end >= 0) {
            if(!isletter(S[end])){end--;continue;}
            if(!isletter(ret[start])){start++;continue;}
            ret[start++] = S[end--];
        } 
        return ret;       
    }   

    string reverseOnlyLetters(string S) {
        return reverseOnlyLetters1(S);
    }


};
// @lc code=end

