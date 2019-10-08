/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<vector<int>*> aa(6,nullptr), bb(6,nullptr);
        int ret = -1;
        for (int j=0;j<6;++j) {
            aa[j] = new vector<int>;
            bb[j] = new vector<int>;
        }
        int len = A.size();
        for (int i=0;i<len;++i) {
            aa[A[i]]->push_back(i);
            bb[B[i]]->push_back(i);
        }
        int size[6] = {0,0,0,0,0,0};
        for (int j=0;j<6;++j) {
            size[j] = aa[j]->size()+bb[j]->size();
        }
        for (int j=0;j<6;++j) {
            if (size[j] < len) continue;
            int pa=0,pb=0;
            for (int i=0;i<len;++i) {
                if (A[pa]==i) {
                    pa++;
                }
                else if (B[pb]==i) {
                    pb++;
                }
                else continue;
                if (i==len-1) ret = len-max(aa[j]->size(),bb[j]->size());
            }
        }
        return ret;
    }
};
// @lc code=end

