/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
/*
  ✔ 3999/3999 cases passed (16 ms / 12 ms)
  ✔ Your runtime beats 57.22 % of cpp submissions
  ✔ Your memory usage beats 21.57 % of cpp submissions (10.7 MB)
*/
        map<char ,int>charMap = {
                                {'I',1}, 
                                {'V',5}, 
                                {'X',10},
                                {'L',50},
                                {'C',100},
                                {'D',500},
                                {'M',1000}};
        char list[7]={'I','V','X','L','C','D','M'};
        int sum=0;
        for (int i=0;i<s.size();++i) {
            sum += charMap.at(s[i]);
            if (i+1 < s.size() && charMap.at(s[i]) < charMap.at(s[i+1])) {
                sum -= 2 * charMap.at(s[i]);
            }
        }
        return sum;
    }
};

