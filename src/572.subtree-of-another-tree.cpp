/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 *  
 * */
#include <deque>
#include <iostream>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    //36ms 21MB
    bool isSubtree1(TreeNode *s, TreeNode *t)
    {
        if (isSame(s, t))
            return true;
        if (!s)
            return false;
        return isSubtree1(s->left, t) || isSubtree1(s->right, t);
    }
    //132ms, 125MB
    bool isSubtree2(TreeNode *s, TreeNode *t)
    {
        deque<int> tDeque;
        travel(t, tDeque);
        return compare(s, tDeque);
    }

private:
    void travel(TreeNode *node, deque<int> &deq)
    {
        if (node)
        {
            deq.push_back(node->val);
            travel(node->left, deq);
            travel(node->right, deq);
        }
    }

    bool compare(TreeNode *node, deque<int> tDeq)
    {
        if (node)
        {
            deque<int> nDeq;
            travel(node, nDeq);
            if (isSame(nDeq, tDeq))
                return true;
            nDeq.pop_front();
            bool l = compare(node->left, tDeq);
            bool r = compare(node->right, tDeq);
            return l || r;
        }
        return false;
    }

    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    bool isSame(deque<int> deq1, deque<int> deq2)
    {
        if (deq1.size() != deq2.size())
            return false;
        for (size_t i = 0; i < deq1.size(); i++)
        {
            if (deq1[i] != deq2[i])
                return false;
        }
        return true;
    }
};

// @lc code=end
