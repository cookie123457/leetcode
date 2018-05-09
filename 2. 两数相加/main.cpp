//
//  main.cpp
//  leetcode
//
//  Created by clown on 2018/5/9.
//  Copyright © 2018 clown. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* cur = result;
        int carry = 0;
        while (l1 || l2)
        {
            int  value1 = l1 == NULL ? 0 : l1->val;
            int  value2 = l2 == NULL ? 0 : l2->val;
            int  sum = value1 + value2 + carry;
            ListNode* tmp = new ListNode(sum % 10);
            cur->next = tmp;
            cur = cur->next;
            carry = sum / 10;
            if (l1)l1 = l1->next;
            if (l2)l2 = l2->next;
        }
        if (carry != 0)
            cur->next = new ListNode(carry);
        return result->next;
        
    }
};
