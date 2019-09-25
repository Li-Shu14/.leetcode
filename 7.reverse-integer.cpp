/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <math.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int reverse1(int x) {
/*
  ✔ Your runtime beats 8.2 % of cpp submissions
  ✔ Your memory usage beats 9.52 % of cpp submissions (8.6 MB)
  事实上我这个LIMIT设置的时候已经出现问题，导致LIMIT最终等于-2147483648，碰巧AC了。
  翻转负号的操作会使得：test case为-2147483648 的情况无法通过！
  本题难点为如何提前判定overflow
*/
        int LIMIT = pow(2,31); //2147483648;
        int ans = 0;
        int flag = 1;
        if (x > LIMIT - 1 || x < -LIMIT) return 0;
        if (x<0) {
            x = -x;
            flag = -1;
        }
        vector<int> vec;
        int res = 0;
        while(x >= 1) {
            res = x%10;
            x = floor(x/10);
            vec.push_back(res);
        }
        
        for (int i = 0; i < vec.size(); ++i) {
            ans += pow(10,vec.size()-1-i) * vec[i];
        }
        if (ans < 0) return 0;
        return ans*flag;
    }


    int reverse2(int x) {
/*
  ✔ Your runtime beats 68.31 % of cpp submissions
  ✔ Your memory usage beats 100 % of cpp submissions (8.1 MB)
  Leetcode: Approach 1: Pop and Push Digits & Check before Overflow
*/
        int rev = 0;
        while (x != 0) {
            // 注意负数取余的结果： -123%10 = -3
            // 注意整数除法会自动取整(直接扔掉小数)！ -123/10 = -12 .
            // 区别于floor： floor(-123/10)=-12, floor(-123.0/10)=-13
            int pop = x % 10; 
            x /= 10; 
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

    int reverse(int x) {
        return reverse2(x);
    }
};    

