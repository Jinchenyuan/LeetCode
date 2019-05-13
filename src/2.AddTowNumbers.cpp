#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int cbit = 0;
        int a = 0;
        int b = 0;
        while (l1 || l2)
        {
            int sum = ((l1) ? (l1->val) : (0)) + ((l2) ? (l2->val) : (0)) + cbit;
            curr->next = new ListNode(sum % 10);
            cbit = sum / 10;
            if(l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            curr = curr->next;
        }
        if (cbit)  
        {
            curr->next = new ListNode(cbit);
        }
        return head->next;
        
    }
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *temp1, *temp2, *tempResult;
        temp1 = l1;
        temp2 = l2;
        tempResult = result;
        int hBit = 0;
        while(temp1 || temp2 || hBit > 0)
        {
            ListNode *node = new ListNode(0);
            if (temp1 && temp2)
            {
                node->val = (temp1->val + temp2->val + hBit) % 10;
                hBit = (temp1->val + temp2->val + hBit) / 10;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1)
            {
                node->val = (temp1->val + hBit) % 10;
                hBit = (temp1->val + hBit) / 10;
                temp1 = temp1->next;
            }
            else if (temp2)
            {
                node->val = (temp2->val + hBit) % 10;
                hBit = (temp2->val + hBit) / 10;
                temp2 = temp2->next;
            }
            else if (hBit > 0)
            {
                node->val = hBit;
                hBit = 0;
            }
            if (tempResult)
            {
                tempResult->next = node;
                tempResult = tempResult->next;
            }
            else
            {
                result = node;
                tempResult = node;
            }
        }
        return result;
    }
};