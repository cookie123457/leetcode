#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//space cost O(n)
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        stack<ListNode*> mystack;
        ListNode* cur = head;
        while (cur != nullptr) {
            mystack.push(cur);
            cur = cur->next;
        }
        
        while (head != nullptr) {
            if (head->val != mystack.top()->val) {
                return false;
            }
            head = head->next;
            mystack.pop();
        }
        return true;
    }
};

//space cost O(n/2)
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* right = head->next;
        ListNode* cur = head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            right = right->next;
            cur = cur->next->next;
        }
        stack<ListNode*> mystack;
        while (right != nullptr) {
            mystack.push(right);
            right = right->next;
        }
        while (!mystack.empty()) {
            if (head->val != mystack.top()->val) {
                return false;
            }
            mystack.pop();
            head = head->next;
        }
        return true;
    }
};


//space cost O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* n1 = head;
        ListNode* n2 = head;
        while (n2->next != nullptr && n2->next->next != nullptr) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        n2 = n1->next;
        n1->next = NULL;
        ListNode* n3 = NULL;
        while (n2 != nullptr) {
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1;
        n2 = head;
        
        bool res = true;
        while (n1 != nullptr && n2 != nullptr) {
            if (n1->val != n2->val) {
                res = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        n1 = n3->next;
        n3->next = NULL;
        while (n1 != nullptr) {
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return res;
    }
};
