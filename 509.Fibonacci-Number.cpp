class Solution {
public:
    int fib1(int N) {
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.3 MB, less than 88.06% of C++ online submissions for Fibonacci Number.
*/
        if (N<=1) return N;
        int last = 0, temp = 0, neww = 1;
        for (int i = 2 ;i<=N; ++i) {
            temp = neww;
            neww = neww + last;
            last = temp;
        }
        return neww;
    }
    int fib2(int N) {
/*
递归
Runtime: 12 ms, faster than 27.04% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.2 MB, less than 91.04% of C++ online submissions for Fibonacci Number.
*/
        if (N<=1) return N;
        return fib2(N-1)+fib2(N-2);
        
    }
    int fib3(int N) {
/*
尾递归，效率陡增！和方法一其实很接近。只是用了“递归”的名号。
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.3 MB, less than 82.09% of C++ online submissions for Fibonacci Number.
*/
        return fibUtil(N,0,1);
    }
    int fibUtil(int N, int a, int b) {
        if (N==0) return a;
        if (N==1) return b;
        return fibUtil(N-1,b,a+b);
        
    }
    
    int fib(int N) {
        return fib1(N);
        //leetcode还给出了直接利用数学规律计算的O(1)算法和利用矩阵乘法的O(logN)算法。
    }
};