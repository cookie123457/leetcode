#include "iostream"

/*
 思路:
 listA + listB = A + 相交 + B + 相交
 listB + listA = B + 相交 + A + 相交
 若A、B有相交部分则在第二次相交处找到，否则则为nullptr。
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        if (!curA || !curB) {
            return NULL;
        }
        while (curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};


