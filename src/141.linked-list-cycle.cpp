/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start

#include <iostream>
/**
 * Definition for singly-linked list.
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        bool findcycle = false;
        if (head == nullptr)
            return findcycle;
        ListNode *pnext = head->next;
        ListNode *p = head;
        while (pnext != nullptr)
        {
            if (pnext == p)
            {
                findcycle = true;
                break;
            }
            pnext = pnext->next;
            p = p->next;
            if (pnext != nullptr)
                pnext = pnext->next;
        }
        return findcycle;
    }
};
// @lc code=end
