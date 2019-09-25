/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome1(int x) {
/*
  ✔ 11509/11509 cases passed (16 ms)
  ✔ Your runtime beats 51.04 % of cpp submissions
  ✔ Your memory usage beats 100 % of cpp submissions (7.9 MB)
  此题直接参考第7题的写法即可。（可以背下来关键的while四句话）。
  最后一个case是2147483647,翻转后overflow需要小心。
*/
        if (x<0) return false;
        int y = x;
        long int r = 0;
        int pop = 0;
        while(x!=0) {
            pop = x%10;
            x /=10;
            r = r*10 + pop;
        }
        return (r==y)? true : false;
    }

    bool isPalindrome2(int x) {
/*
  ✔ Your runtime beats 98.11 % of cpp submissions
  ✔ Your memory usage beats 78.18 % of cpp submissions (8.2 MB)
  仅仅是把pop那一句省略了···但为什么空间反而变大了？！
  原来是vscode有bug，连续提交两次，则后面提交的速度会变快很多！！
  重新打开vscode再提交一次就恢复正常了。
  ✔ 11509/11509 cases passed (16 ms)
  ✔ Your runtime beats 51.04 % of cpp submissions
  ✔ Your memory usage beats 100 % of cpp submissions (8 MB)
*/
        if (x<0) return false;
        int y = x;
        long int r = 0;
        int pop = 0;
        while(x!=0) {
            r = r*10 + x%10;
            x /=10;   
        }
        return (r==y)? true : false;
    }
    bool isPalindrome(int x) {
        return isPalindrome2(x);
    }
};

