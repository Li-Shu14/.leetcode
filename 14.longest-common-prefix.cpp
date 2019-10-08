/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
/*
  ✔ 118/118 cases passed (8 ms)
  ✔ Your runtime beats 54.08 % of cpp submissions
  ✔ Your memory usage beats 75.81 % of cpp submissions (8.9 MB)
*/
        int shortest = 2147483647;
        string ret = "";
        if (strs.size()==0) return "";
        for (vector<string>::iterator it=strs.begin();it!=strs.end();++it) {
            shortest = (it->size() > shortest)? shortest:it->size();
        }
        for (int i = 0; i<shortest; ++i) {
            for (vector<string>::iterator it=strs.begin()+1;it!=strs.end();++it) {
                if (strs.begin()->at(i)!=it->at(i)) {
                    return ret;
                }
            }
            ret += strs.begin()->at(i);
        }
        return ret;
    }
};

