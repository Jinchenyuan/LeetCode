/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.

 */
//另外一种 O(1) 空间的解法，就是反转链表，这里就不编码了
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    //O(N) time, O(N) space
    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        int len = 0, idx = 1;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            len++;
        }
        p = head;
        vector<int> data;
        while (p)
        {
            if (idx > len / 2)
            {
                if (!(len % 2 == 1 && idx == len / 2 + 1))
                {
                    if (p->val != data.back())
                        return false;
                    data.pop_back();
                }
            }
            else
            {
                data.push_back(p->val);
            }
            idx++;
            p = p->next;
        }
        return true;
    }
};
// @lc code=end
