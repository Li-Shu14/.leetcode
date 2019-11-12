/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//  };
/*
方法一： 两次循环
208/208 cases passed (4 ms)
Your runtime beats 85.61 % of cpp submissions
Your memory usage beats 94.74 % of cpp submissions (8.5 MB)
遍历两次，第一次求长度。第二次找结点。且处理特殊情况的方式比较笨。没有形成统一的优美的方式。

方法二： 两次循环
208/208 cases passed (4 ms)
Your runtime beats 85.61 % of cpp submissions
Your memory usage beats 75 % of cpp submissions (8.6 MB)
上述方法的改进，通过添加指向头部的虚拟结点可以避免对特殊情况的讨论。更美丽。但是多一个结点，占用的空间变大了些。

方法三： 单次循环————快慢指针
Runtime: 4 ms, faster than 85.61% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 8.6 MB, less than 71.05% of C++ online submissions for Remove Nth Node From End of List.
*/
class Solution {
public:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        int size = 1;
        ListNode* p=head;
        while(p->next!=NULL){
            p = p->next;
            size++;
        }
        if (size==1 && n==1) return NULL;
        if (size==n) return head->next;
        p = head;
        for (int i = 2; i<= size-n;++i){
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        int size = 0;
        ListNode vir(0);
        vir.next = head;
        ListNode* p = &vir;
        while(p->next!=NULL){
            p = p->next;
            size++;
        }
        p = &vir;
        for (int i = 0; i< size-n;++i){
            p = p->next;
        }
        p->next = p->next->next;
        return vir.next;
    }

    ListNode* removeNthFromEnd3(ListNode* head, int n) {
        int size = 0;
        ListNode vir(0);
        vir.next = head;
        ListNode *p = &vir, *q = &vir;
        int i = 0;
        while(p->next!=NULL){
            p = p->next;
            size++;
            if (i<size-n) {
                i++;
                q = q->next;
            }
        }
        q->next = q->next->next;
        return vir.next;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd3(head,n);
    }
};
// @lc code=end

