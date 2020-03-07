/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
方法一：归并排序的递归
16/16 cases passed (84 ms)
Your runtime beats 21.53 % of cpp submissions
Your memory usage beats 5 % of cpp submissions (28 MB)
归并排序（递归），参考自leetcode标准解法。
https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/

方法二：归并排序的迭代
从leetcode官方解法python代码直接改的，没调通。

方法三：归并排序的迭代
16/16 cases passed (52 ms)
Your runtime beats 69.02 % of cpp submissions
Your memory usage beats 15 % of cpp submissions (14.7 MB)
https://leetcode-cn.com/problems/sort-list/solution/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/
这个人讲的很清晰
 */

class Solution {
public:
    ListNode* sortList1(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* fast = head->next;//用快慢指针确定中点
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next; //右边的开头
        slow->next = NULL; //从中间断开
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        return Merge(left,right); //官方解答里没有单独用新函数来表示合并过程
    }

    ListNode* Merge(ListNode* left, ListNode* right) {
        ListNode* h = new ListNode(0);
        ListNode* res = h;
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = ((left != NULL) ? left : right);
        return res->next;
    }

    ListNode* sortList2(ListNode* head){
        ListNode* h = head;
        int length = 0, intv = 1, i = 0;
        ListNode* res = new ListNode(0);
        res->next = head;
        // merge the list in different intv
        while( intv<length) {
           ListNode* pre = res;
           h = res->next; 
           while(h!=NULL) {
               //get the two merge head `h1`, `h2`
               ListNode* h1 = h;
               i = intv;
               while(i!=0 && h!=NULL) {
                   h = h->next;
                   i--;
               }
               if (i) break; //no need to merge because the `h2` is None.
               ListNode* h2 = h;
               int i = intv;
               while(i!=0 && h!=NULL) {
                   h = h->next;
                   i--;
               }
               int c1 = intv, c2 = intv-i; //the `c2`: length of `h2` can be small than the `intv`.
               //merge the `h1` and `h2`.
                while( c1!=0 && c2!=0) {
                    if (h1->val < h2->val) {
                        pre->next = h1;
                        h1 = h1->next;
                        c1--;
                    }
                    else {
                        pre->next = h2;
                        h2 = h2->next;
                        c2--;
                    }
                }
                pre->next = (c1=0) ? h1 : h2;
                while(c1>0 || c2>0) {
                    pre = pre->next;
                    c1--;
                    c2--;
                }
                pre->next = h;
           }
           intv *=2;
        }
        return res->next;
    }

    ListNode* sortList3(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        
        if (!p) return nullptr;
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }


    ListNode* sortList(ListNode* head) {   
        return sortList3(head);
    }
    
};
// @lc code=end

