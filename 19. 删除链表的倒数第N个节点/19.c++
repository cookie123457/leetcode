#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return NULL;
        }
        ListNode* pre = head;
        ListNode* nex = head;
        for (int i=0; i<n; i++) {
            pre = pre->next;
        }
        
        if (pre == NULL) {
            return nex->next;
        }
        
        while (pre->next != nullptr) {
            pre = pre->next;
            nex = nex->next;
        }
        
        nex->next = nex->next->next;
        return head;
    }
};
