#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* iternode = head;
        while (iternode != nullptr) {
            count++;
            iternode = iternode->next;
        }
        
        iternode = head;
        count = count / 2;
        while (iternode && count--) {
            iternode = iternode->next;
        }
        return iternode;
    }
};

