/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
FLoyd双阶段方法：
第一阶段：
快慢指针同时从头部出发。
第二阶段：
两个慢指针分别从头部、相遇点出发，最终一定在环入口处相遇。
16/16 cases passed (12 ms)
Your runtime beats 77 % of cpp submissions
Your memory usage beats 66.67 % of cpp submissions (9.8 MB)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return NULL;
        ListNode* intersect = getIntersect(head);
        if (intersect == NULL) return NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = intersect;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }

    ListNode* getIntersect(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare != NULL && hare->next != NULL) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return tortoise;
            }
        }
        return NULL;
    }

};
// @lc code=end

