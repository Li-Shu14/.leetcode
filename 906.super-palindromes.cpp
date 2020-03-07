/*
 * @lc app=leetcode id=906 lang=cpp
 *
 * [906] Super Palindromes
 */

// @lc code=start
class Solution {
public:
    int superpalindromesInRange1(string L, string R) {
        long long int l = stoll(L);
        long long int r = stoll(R);
        long long int l_sq = ceil(sqrt(l));
        long long int r_sq = floor(sqrt(r));
        
        int ret = 0;
        
        for (long long int i = l_sq; i <=r_sq; ++i) {
            cout << i <<endl;
            if (ispalin(i) && ispalin(i*i)) ret++;
        }
        return ret;

    }

    bool ispalin(long long int num) {
        long long int rev = 0;
        while(num!=0) {
            rev = num%10 + rev*10;
            num = num/10;
            cout<<num<<endl;
        }
        cout <<rev<<endl;
        return (rev==num);
    }

    int superpalindromesInRange2(string L, string R) {
        int res = 0;
        long left = stol(L), right = stol(R);
        helper("", left, right, res);
        for (char c = '0'; c <= '9'; ++c) {
            helper(string(1, c), left, right, res);
        }
        return res;
    }
    void helper(string cur, long& left, long& right, int& res) {
        if (cur.size() > 9) return;
        if (!cur.empty() && cur[0] != '0') {
            long num = stol(cur);
            num *= num;
            if (num > right) return;
            if (num >= left && isPalindrome(to_string(num))) ++res;
            }
            for (char c = '0'; c <= '9'; ++c) {
            helper(string(1, c) + cur + string(1, c), left, right, res);
        }
    }
    bool isPalindrome(string str) {
        int left = 0, right = (int)str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    
    int superpalindromesInRange3(string L, string R) {

        long long ll = stoll(L), rr = stoll(R);
        int MAGIC = 100000, cnt = 0;
        
        // count odd length;
        for (int k = 1; k < MAGIC; ++k) 
        {
            string s1 = to_string(k), s2 = "";
            for (int i = s1.length() - 2; i >= 0; --i)
            {
                s2 += s1[i];
            }
            long long v = stoll(s1+s2);
            v *= v;
            if (v > rr) break;
            if (v >= ll && isPalindrome(lltos(v))) 
            {
                cnt++;
            }
        }
    }  
            // count even length;
        for (int k = 1; k < MAGIC; ++k) 
        {
            string s1 = to_string(k), s2 = "";
            for (int i = s1.length() - 1; i >= 0; --i)
            {
                s2 += s1[i];
            }
            long long v = stoll(s1+s2);
            v *= v;
            if (v > rr) break;
            if (v >= ll && isPalindrome(lltos(v))) 
            {
                cnt++;
            }
        }

        return cnt;
    }

    string lltos(long long ll)  {  
        ostringstream os;  
        os<<ll;  
        string result;  
        istringstream is(os.str());  
        is>>result;  
        return result;  
    }  
    long long stoll(string str)  {  
        long long result;  
        istringstream is(str);  
        is >> result;  
        return result;  
    }


    int superpalindromesInRange(string L, string R) {
        return superpalindromesInRange3(L,R);
    }

};
// @lc code=end

