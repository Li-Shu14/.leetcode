/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
leetcode官方标准方法一：动态规划。
588/588 cases passed (176 ms)
Your runtime beats 28.45 % of cpp submissions
Your memory usage beats 90.38 % of cpp submissions (9.3 MB)
O(n*sqrt(n)),  O(n)

方法二：贪心枚举
588/588 cases passed (44 ms)
Your runtime beats 86.85 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6.9 MB)
O(n^(h/2)), O(sqrt(n))

方法三：贪心 + BFS 方法二的进一步提炼
588/588 cases passed (408 ms)
Your runtime beats 7.73 % of cpp submissions
Your memory usage beats 11.54 % of cpp submissions (33.9 MB)
O(n^(h/2)), O(sqrt(n) ^ h) 
虽然该方法的理论时间复杂度和方法二相同，但是却慢这么多···！
注意在这里使用set的代替queue能够极大地提高效率！

方法四：数学运算（具体见leecode-cn）
588/588 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (6.1 MB)
O(sqrt(n)), O(1)

 */

// @lc code=start
class Solution {
public:
    int numSquares1(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        int r = (int)sqrt(n) + 1;
        vector<int> square(r+1,0);
        for (int i =1;i<r+1;i++){
            square[i] = i * i;
        }
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2;i<n+1;i++) {
            int min_count = INT_MAX;
            int r = (int)sqrt(i) + 1;
            for (int j=1;j<r;j++) {
                min_count = min(dp[i-square[j]],min_count);
            }
            dp[i] = 1 + min_count;
        }
        return dp[n];
    }

    set<int> square_nums;        

    bool is_divided_by(int n, int count) {
        if (count == 1) {
            if (square_nums.find(n)!=square_nums.end()) return true;
            else return false;
        }
        for (int square : square_nums) {
            if (is_divided_by(n - square, count - 1)) return true;
        }
        return false;
    }

    int numSquares2(int n) {
        square_nums.clear();
        for (int i = 1; i * i <= n; ++i) {
            square_nums.insert(i * i);
        }

        int count = 1;
        for (count = 1; count <= n; ++count) {
            if (is_divided_by(n, count)) return count;
        }
        return count;
    }

    int numSquares3(int n) {
        vector<int> square_nums;
        for (int i = 1; i * i <= n; ++i) {
        square_nums.push_back(i * i);
        }

        set<int> queue;
        queue.insert(n);

        int level = 0;
        while (queue.size() > 0) {
        level += 1;
        set<int> next_queue;;
        for (int remainder : queue) {
            for (int square : square_nums) {
                if (remainder == square) return level;
                else if (remainder < square) break;
                else next_queue.insert(remainder - square);
            }
        }
        queue = next_queue;
        }
        return level;
    }

    bool isSquare(int n) {
        int sq = (int) sqrt(n);
        return n == sq * sq;
    }

    int numSquares4(int n) {
        // four-square and three-square theorems.
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;

        if (isSquare(n)) return 1;
        // enumeration to check if the number can be decomposed into sum of two squares.
        for (int i = 1; i * i <= n; ++i) {
            if (isSquare(n - i * i)) return 2;
        }
        // bottom case of three-square theorem.
        return 3;
    }


    int numSquares(int n) {
        return numSquares4(n);
    }

};
// @lc code=end

