/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
/*
  ✔ 3999/3999 cases passed (16 ms) 这个时间在8 12 16之间来回变化，不知道为啥。
  ✔ Your runtime beats 27.94 % of cpp submissions 
  ✔ Your memory usage beats 36.84 % of cpp submissions (10.2 MB)
这真是我第一次 一次AC的题目···查表法其实没有啥难度···
*/
public:
    const string table[4][10] = {"","I","II","III","IV","V","VI","VII","VIII","IX",
                               "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                               "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                               "","M","MM","MMM"};
    string intToRoman1(int num) {
        vector<string> vec;
        int order = 0;
        string s;
        while (num > 0) {
            int res = num % 10;
            num /= 10;
            vec.push_back(table[order][res]);
            order++;
        }
        for (vector<string>::iterator it=vec.end()-1;it>=vec.begin();it--){
            s.append(*it);
        }
        return s;
    }

    string intToRoman2(int num) {
/*
网上看到的递归方法JAVA改编。
最后在返回的时候似乎我没有改编好，编译错误。需要专门练练递归的方法。
*/
        if (num == 0) return "";
        int base[13]    = {1000, 900, 500, 400,  100,  90,  50,  40,   10,   9,    5,   4,    1};
        string sym[13]  = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int len = end(base)-begin(base);
        for (int i = 0; i < len; ++i) {
            if (num >= base[i]) {
                return (sym[i] + intToRoman2(num - base[i]));
            }
        }
    }
        

    string intToRoman(int num) {
        return intToRoman1(num);
    }
};

