#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *left = head, *right = head->next, *temp = NULL, *ret = NULL;
        while (left && right)
        {
            if (temp)
                temp->next = right;
            left->next = right->next;
            right->next = left;
            if (!ret)
                ret = right;
            temp = left;
            left = left->next;
            if (left)
                right = left->next;
        }
        return ret == NULL ? left : ret;
    }
};