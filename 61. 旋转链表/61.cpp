#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        
        int count = 1;
        ListNode* pre = head;
        ListNode* res;
        ListNode* temp;
        
        while (pre->next != nullptr) {
            count++;
            pre = pre->next;
        }
        
        pre->next = head;
        int n = count - k % count;
        temp = pre;
        while (n-- != 0) {
            temp = temp->next;
        }
        res = temp->next;
        temp->next = NULL;
        return res;
    }
};


