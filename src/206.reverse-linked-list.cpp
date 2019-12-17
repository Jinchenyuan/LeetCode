/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *ret = head, *next = head->next;
        ret->next = NULL;
        while (next)
        {
            ListNode *tmp = next->next;
            next->next = ret;
            ret = next;
            next = tmp;
        }
        return ret;
    }
};
// @lc code=end

