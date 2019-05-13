#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL;
        ListNode *idx = NULL;
        while (l1 || l2)
        {
            ListNode *temp = NULL;
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    temp = l1;
                    l1 = l1->next;
                }
                else
                {
                    temp = l2;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }
            
            if (idx)
            {
                idx->next = temp;
                idx = idx->next;
            }
            else
            {
                idx = temp;
                ret = idx;
            }
            
            if (!l1 && l2)
            {
                idx->next = l2;
                break;
            }
            if (!l2 && l1)
            {
                idx->next = l1;
                break;
            }
            
        }
        return ret;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL;
        ListNode *idx = NULL;
        while (l1 || l2)
        {
            ListNode *temp = NULL;
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    temp = l1;
                    l1 = l1->next;
                }
                else
                {
                    temp = l2;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }
            if (idx)
            {
                idx->next = temp;
                idx = idx->next;
            }
            else
            {
                idx = temp;
                ret = idx;
            }
            
        }
        return ret;
    }
};