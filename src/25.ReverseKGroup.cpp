#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reverseList(ListNode* start, ListNode* end, int length)
    {
        ListNode *next = NULL, *node1 = start, *node2 = start->next;
        for (int i = 0; i < length - 1; i++)
        {
            next = node2->next;
            node2->next = node1;
            if (next)
            {
                node1 = node2;
                node2 = next;
                if (node2)
                    next = node2->next;
            }
            
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 0 || !head)
            return head;
        ListNode *ret = NULL, *start = head, *end = head, *temp = NULL, *next = NULL;
        int cnt = 1;
        while(end)
        {
            while (cnt < k)
            {
                if (end->next)
                {
                    end = end->next;
                    cnt++;
                }
                else
                    break;
            }
            if (cnt != k)
                break;
            next = end->next;
            reverseList(start, end, cnt);
            start->next = next;
            if (!ret)
                ret = end;
            cnt = 1;
            if (temp)
                temp->next = end;
            temp = start;
            end = next;
            start = end;
        }
        return ret ? ret : head;
    }
};