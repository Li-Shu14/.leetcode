/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
/*
76/76 cases passed (4 ms)
Your runtime beats 58.46 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.2 MB)
*/
class Solution {
public:
    bool isValid(string s) {  //vec.back()
        vector<char> z;
        if (s=="") return true;
        
        for (char c:s) {
            if (z.size()==0 && isback(c)) return false;
            if (!isback(c)) {
                z.push_back(c);
                continue;
            }
            int dif = c-z.back();
            if (isback(c) && (dif == 1 || dif == 2)) {
                z.pop_back();
            }
            else return false;
        }
        if (z.size() == 0) return true;
        else return false;
    }

    
private:
    bool isback(char c) {
        if (c==')' || c==']' || c=='}') return true;
        else return false;
    }
};
// @lc code=end

