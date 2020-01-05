/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include <vector>
// using namespace std;
/*
方法一：
法一的写法有问题！其实对于62题也是如此。那就是——不能直接用指针去new一个二维数组！！否则会出现奇怪的内存问题。正确的写法如下！！
    int **a = new int *[m];  
    for(int i=0; i<m; ++i) {  
        a[i] = new int[n];  
    }  
然后结束的时候需要回收内存：
    for(int i=0; i<m; ++i) {  
        delete[] a[i];  
    }  
    // 然后回收高一级的动态数组.  
    delete[] a;  
然后注意这种方式的内存不是连续的，a[i * width + j] 这种索引就会有问题。
*/

class Solution {
public:
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int *a = new int[m,n];
        a[0,0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            a[i,0] = a[i-1,0];
            if (obstacleGrid[i][0] == 1) a[i,0] = 0;
        }
        for (int j = 1; j < n;++j) {
            a[0,j] = a[0,j-1];
            if (obstacleGrid[0][j] == 1) a[0,j] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                a[i,j] = a[i-1,j] + a[i,j-1];
                if (obstacleGrid[i][j] == 1) a[i,j] = 0;
            }
        }
        return a[m-1,n-1];
    }

    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long int **a = new long int *[m];  
        for(int i=0; i<m; ++i) {  
            a[i] = new long int[n];  
        }  
        a[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            a[i][0] = a[i-1][0];
            if (obstacleGrid[i][0] == 1) a[i][0] = 0;
        }
        for (int j = 1; j < n;++j) {
            a[0][j] = a[0][j-1];
            if (obstacleGrid[0][j] == 1) a[0][j] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                a[i][j] = a[i-1][j] + a[i][j-1];
                if (obstacleGrid[i][j] == 1) a[i][j] = 0;
            }
        }
        return a[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstacles2(obstacleGrid);
    }
};
