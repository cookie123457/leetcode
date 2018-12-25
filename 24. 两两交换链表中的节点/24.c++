#include "iostream"
#include <stack>
using namespace std;
/*
 思路1:遍历链表并压栈，若栈的大小等于2，则依次弹出栈中元素，并按照弹出顺序重新连接，重复直到全部遍历完成；
 思路2:使用变量记录每一组的两个节点，直接逆序调整。
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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* start = NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        int count = 1;
        while (cur != nullptr) {
            next = cur->next;
            if (count == 2) {
                start = pre == nullptr ? head : pre->next;
                head = pre == nullptr ? cur : head;
                resign(pre, start, cur, next);
                pre = start;
                count = 0;
            }
            count++;
            cur = next;
        }
        return head;
    }
    
    void resign(ListNode* left, ListNode* start, ListNode* end, ListNode* right) {
        ListNode* pre = start;
        ListNode* cur = start->next;
        ListNode* next = NULL;
        while (cur != right) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            if (left != nullptr) {
                left->next = end;
            }
            start->next = right;
        }
    }
};

