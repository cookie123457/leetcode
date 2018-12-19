#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* res = nullptr;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = res;
            res = cur;
            cur = temp;
        }
        return res;
        
    }
};