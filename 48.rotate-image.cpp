/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 * √ Accepted
  √ 21/21 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (8.9 MB)
  真水啊这题。
  就是   i <= (n-1)/2   j < n/2  这两个判定形式不够统一，还不美。不过看官方解答方法三稍微美一些，统一采用的是小于符号。即  i < (n+1)/2, j < n/2  ！！！记住这个结论哦！
 */
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i <= (n-1)/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

