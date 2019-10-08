/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mi = *min_element(A.begin(),A.end());
        int ma = *max_element(A.begin(),A.end());
        return max(ma-mi-2*K,0);
    }
};
// @lc code=end

