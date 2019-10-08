/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap1(vector<int>& A, int L, int M) {
/*
51/51 cases passed (716 ms)
Your runtime beats 5.07 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.6 MB)
暴力搜索
*/
        int max_sum = 0;
        int len = A.size();
        for (int i = 0;i<len-L+1;++i) {
            for(int j =0;j<len-M+1;++j) {
                if (max(i+L-1,j+M-1) - min(i,j) + 1 < L+M) continue;//overlap
                int sum = accumulate(A.begin()+i,A.begin()+i+L,0) + accumulate(A.begin()+j,A.begin()+j+M,0);
                max_sum = max(max_sum,sum);
            }
        }
        return max_sum;
    }
    int maxSumTwoNoOverlap2(vector<int>& A, int L, int M) {
/*
51/51 cases passed (36 ms)
Your runtime beats 6.27 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.6 MB)
提前将和求出来存好。
?!!我的耗时已经减小了10多倍···怎么排名还是很后面。
*/      
        int max_sum = 0;
        int len = A.size();
        int suml[len-L+1], summ[len-M+1];
        suml[0] = accumulate(A.begin(),A.begin()+L,0);
        summ[0] = accumulate(A.begin(),A.begin()+M,0);
        for (int i = 1;i<len-L+1;++i) {
            suml[i] = suml[i-1]-A[i-1]+A[i+L-1];
        }
        for (int j = 1;j<len-M+1;++j) {
            summ[j] = summ[j-1]-A[j-1]+A[j+M-1]; 
        }
        for (int i = 0;i<len-L+1;++i) {
            for(int j =0;j<len-M+1;++j) {
                if (max(i+L-1,j+M-1) - min(i,j) + 1 < L+M) continue;//overlap
                // int sum = accumulate(A.begin()+i,A.begin()+i+L,0) + accumulate(A.begin()+j,A.begin()+j+M,0);
                int sum = suml[i] + summ[j];
                max_sum = max(max_sum,sum);
            }
        }
        return max_sum;
    }

    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return maxSumTwoNoOverlap2(A,L,M);
    }
};
// @lc code=end

