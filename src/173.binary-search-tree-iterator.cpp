#include<iostream>
#include<list>
#include<stack>
using namespace std;

/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        root = root;
        for (TreeNode *cur = root; cur != NULL; cur = cur->left)
        {
            st.push(cur);
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ans = st.top();
        st.pop();
        for (TreeNode *cur = ans->right; cur != NULL; cur = cur->left)
        {
            st.push(cur);
        }
        return ans->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size() > 0;
    }

private:
    TreeNode *root;
    stack<TreeNode *> st;
};

class BSTIterator2 {
public:
    BSTIterator2(TreeNode* root) {
        midTraverse(root);
        ite = data.begin();
    }

    /** @return the next smallest number */
    int next() {
        if (ite != data.end() && data.size() > 0)
        {
            list<int>::iterator tmp = ite;
            ite++;
            return *tmp;
        }
        if (data.size() > 0)
            return data.back();
        return 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (ite != data.end() && data.size() > 0)
        {
            return true;
        }
        return false;
    }

private:
    void midTraverse(TreeNode* root)
    {
        if (root)
        {
            midTraverse(root->left);
            data.push_back(root->val);
            midTraverse(root->right);
        }
    }
    list<int> data;
    list<int>::iterator ite;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

