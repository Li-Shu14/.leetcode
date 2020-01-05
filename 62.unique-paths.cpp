/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths 
 */

/*
方法一：直接通过数学规律
需要经过(m-1)个向右和(n-1)个向下，总共需要走过(m+n-2)个格子，计算从(m+n-2)个格子中选(m-1)个向右的格子，有C_{m+n-2}^{m-1}种组合，即等价于求有多少条路径。
  √ 62/62 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (8.1 MB)
方法二：动态规划
*/
class Solution {
public:
    int uniquePaths1(int m, int n) {
        double value = 1;
        for (int i = 1; i <= n - 1; i++) {
            value *= ((double) (m + i - 1) / (double) i);
        }
        return (int) round(value);
    }

    int uniquePaths2(int m, int n) {
        int *a = new int[m,n];
        for (int i = 0; i < m; ++i) {
            a[i,0] = 1;
        }
        for (int j = 0; j < n;++j) {
            a[0,j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                a[i,j] = a[i-1,j] + a[i,j-1];
            }
        }
        return a[m-1,n-1];
    }
    int uniquePaths(int m, int n) {
        return uniquePaths2(m,n);
    }


};
