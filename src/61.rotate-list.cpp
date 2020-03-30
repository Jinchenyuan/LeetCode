/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *p = head;
        ListNode *end = p;
        ListNode *ret = NULL;
        while (p)
        {
            len++;
            end = p;
            p = p->next;
        }
        
        if (len > 0)
        {
            int step = (len - (k % len)) % len;
            if (step > 0)
            {
                ListNode *p = NULL;
                for (int i = 0; i < step; i++)
                {
                    p = p ? p->next : head;
                }
                ret = p->next;
                p->next = NULL;
                end->next = head;
            }
            else
            {
                ret = head;
            }
        }
        return ret;
    }
};
// @lc code=end

