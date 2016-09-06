//
//  addnum.cpp
//  xcode
//
//  Created by Gokul Nadathur on 9/5/16.
//  Copyright © 2016 Gokul Nadathur. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = 0, c = 0;
        ListNode *cur1 = l1, *cur2 = l2, *head = NULL, *cur3 = NULL;
        auto val = [] (ListNode* c) { return c ? c->val : 0; };
        auto next = [](ListNode* c) { return c ? c->next : NULL;};
        while (cur1 || cur2) {
            s = c + val(cur1)  + val(cur2);
            c = s/10;
            s = s % 10;
            auto n = new ListNode(s);
            if (!head) {
                head = n;
            } else {
                cur3->next = n;
            }
            cur3 = n;
            cur1 = next(cur1);
            cur2 = next(cur2);
        }
        if (c) {
            auto n = new ListNode(c);
            cur3->next = n;
        }
        return head;
    }
};

int main(int argc, char** argv)
{
    return 0;
}