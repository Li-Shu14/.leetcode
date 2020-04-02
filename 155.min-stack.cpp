/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
方法一：抄leetcode
18/18 cases passed (32 ms)
Your runtime beats 68.05 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (16 MB)

方法二：同上。理论上该方法的空间占用更小
18/18 cases passed (32 ms)
Your runtime beats 68.05 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (16 MB)
 */

// @lc code=start
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    // MinStack() {}
    void push(int x) {
        m_stack.push(x);
        if (m_stack_min.empty() || x <= m_stack_min.top()) m_stack_min.push(x);
        //小等于能够处理重复数字的情况！！
    }
    
    void pop() {
        if(m_stack.top() == m_stack_min.top()) m_stack_min.pop();
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_stack_min.top();
    }

private:
    stack<int> m_stack;
    stack<int> m_stack_min;
};

class MinStack2 {
public:
    /** initialize your data structure here. */
    // MinStack() {}
    
    void push(int x) {
        m_stack.push(x);
        if(m_stack_min.empty()) m_stack_min.push(x);
        else if(x < m_stack_min.top()) m_stack_min.push(x);
        else m_stack_min.push(m_stack_min.top());
    }
    
    void pop() {
        m_stack_min.pop();
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_stack_min.top();
    }

private:
    stack<int> m_stack;
    stack<int> m_stack_min;
};

// @lc code=end

