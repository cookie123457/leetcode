#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL&&head->val == val) {
            head = head->next;
        }
        if(head == NULL) {
            return head;
        }
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
