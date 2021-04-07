/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode *p1 = head, *p2 = head->next; 

        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        return mergeLists(sortList(head), sortList(p2));
    }
    ListNode *mergeLists(ListNode* head1, ListNode* head2){
        ListNode *p1 = head1,  *p2=head2;
        static ListNode dummy(0);

        ListNode *tail = &dummy;

        while(p1 && p2){
            if(p1->val < p2->val){
                tail->next = p1;
                p1 = p1->next;
            }else{
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if (p1) tail->next = p1;
        if (p2) tail->next = p2;

        return dummy.next;
    }
};
// @lc code=end

