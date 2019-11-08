/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;
/*
76/76 cases passed (4 ms)
Your runtime beats 58.46 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.2 MB)
*/
class Solution {
public:
    bool isValid1(string s) {  //vec.back()
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
    bool isValid2(string s) {
        stack<char> stack;

        if(s.length() == 0){
            return true;
        }
        if(s.length() == 1){
            return false;
        }
        
        for(int i =0 ; i < s.length(); i++){
            char c = s[i];
            if(c == '}'|| c == ')' || c == ']'){
                if(stack.size() == 0 ) return false;
                if(c == '}' && stack.top() != '{') return false;
                if(c == ')' && stack.top() != '(') return false;
                if(c == ']' && stack.top() != '[') return false;
                stack.pop();
                
            } else {
                stack.push(c);
            }
        }
        if(stack.size() == 0) return true;
        return false;
    }

    bool isValid(string s) {
        return isValid2(s);
    }

private:
    bool isback(char c) {
        if (c==')' || c==']' || c=='}') return true;
        else return false;
    }
};
// @lc code=end

