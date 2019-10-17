/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start

#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        int lenA = 0, lenB = 0;
        while (pA || pB)
        {
            if (pA)
            {
                lenA++;
                pA = pA->next;
            }
            if (pB)
            {
                lenB++;
                pB = pB->next;
            }
        }
        if (lenA > 0 && lenB > 0)
        {
            pA = headA;
            pB = headB;

            if (lenA > lenB)
            {
                for (size_t i = 0; i < lenA - lenB; i++)
                    pA = pA->next;
            }
            else if(lenA < lenB)
            {
                for (size_t i = 0; i < lenB - lenA; i++)
                    pB = pB->next;
            }
            bool sign = false;
            int val = 0;
            while (pA)
            {
                if (sign)
                {
                    if (pA->val != pB->val)
                    {
                        sign = false;
                    }
                }
                else
                {
                    if (pA->val == pB->val)
                    {
                        sign = true;
                        val = pA->val;
                    }
                }
                pA = pA->next;
                pB = pB->next;
            }
            if (sign)
            {
                return new ListNode(val);
            }
        }
        return NULL;
    }
};

int main(void)
{
    ListNode *pa = new ListNode(4);
    ListNode *paTemp = pa;
    paTemp->next = new ListNode(1);
    paTemp = paTemp->next;
    paTemp->next = new ListNode(8);
    paTemp = paTemp->next;
    paTemp->next = new ListNode(4);
    paTemp = paTemp->next;
    paTemp->next = new ListNode(5);

    ListNode *pb = new ListNode(5);
    ListNode *pbTemp = pb;
    pbTemp->next = new ListNode(0);
    pbTemp = pbTemp->next;
    pbTemp->next = new ListNode(1);
    pbTemp = pbTemp->next;
    pbTemp->next = new ListNode(8);
    pbTemp = pbTemp->next;
    pbTemp->next = new ListNode(4);
    pbTemp = pbTemp->next;
    pbTemp->next = new ListNode(5);

    Solution s;
    ListNode *ret = s.getIntersectionNode(pa, pb);
    if (ret)
    {
        cout << ret->val << endl;
    }
    return 0;
}
// @lc code=end

