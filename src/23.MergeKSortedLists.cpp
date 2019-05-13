#include <iostream>
#include <vector>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void connect(ListNode *&head, ListNode *&cur, ListNode *node)
    {
        if (head == NULL) {
            head = cur = node;
        } else {
            cur->next = node;
            cur = cur->next;
        }
    }
    ListNode* merge(ListNode *a, ListNode *b)
    {
        ListNode *head = NULL, *cur = NULL;
        while (a != NULL || b != NULL) {
            if (a != NULL && b != NULL) {
                if (a->val < b->val) {
                    connect(head, cur, a);
                    a = a->next;
                } else {
                    connect(head, cur, b);
                    b = b->next;
                }
            } else if (a != NULL) {
                connect(head, cur, a);
                a = a->next;
            } else {
                connect(head, cur, b);
                b = b->next;
            }
        }
        return head;
    }
    ListNode* mergeKLists1(vector<ListNode *> &lists)
    {
        int sz = lists.size();
        while (sz > 1) {
            int j = sz - 1;
            for (int i = 0; i < sz / 2; i++) {
                lists[i] = merge(lists[i], lists[j]);
                j--;
            }
            if (sz % 2 == 1)
                sz = sz / 2 + 1;
            else
                sz = sz / 2;
        }
        return sz > 0 ? lists[0] : NULL;
    }


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        ListNode *ret = NULL;
        int len = lists.size();
        if (len > 0)
            ret = lists[0];
        else
            return NULL;
        for (int i = 1; i < len; i++)
        {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }
};