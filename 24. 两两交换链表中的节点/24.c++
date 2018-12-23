#include "iostream"
#include <stack>
using namespace std;
/*
 思路1:遍历链表并压栈，若栈的大小等于2，则依次弹出栈中元素，并按照弹出顺序重新连接，重复直到全部遍历完成；
 思路2:
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        stack <ListNode*> my_stack;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newhead = head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while (cur != nullptr) {
            next = cur->next;
            my_stack.push(cur);
            if (my_stack.size() == 2) {
                pre = resign(&my_stack, pre, next);
                newhead = newhead  == head ? cur : newhead;
            }
            cur = next;
        }
        return newhead;
    }
    
    ListNode* resign(stack<ListNode*> *stack, ListNode* left, ListNode* right) {
        ListNode* cur = stack->top();
        stack->pop();
        if (left != nullptr) {
            left->next = cur;
        }
        ListNode* next = NULL;
        while (!stack->empty()) {
            next = stack->top();
            stack->pop();
            cur->next = next;
            cur = next;
        }
        cur->next = right;
        return cur;
    }
};

