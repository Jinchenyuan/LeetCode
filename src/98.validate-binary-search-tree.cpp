#include <iostream>
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void front_traversal(TreeNode* root, int parentValue, int isLeft, bool &ret)
    {
        if (root)
        {
            if (root->val >= parentValue && isLeft)
                ret = false;
            if (root->val <= parentValue && !isLeft)
                ret = false;
            front_traversal(root->left, parentValue, isLeft, ret);
            front_traversal(root->right, parentValue, isLeft, ret);
        }
    }

    bool checkSubTree(TreeNode* root, int parentValue, bool isLeft)
    {
        if (root)
        {
            if (root->val >= parentValue && isLeft)
                return false;
            if (root->val <= parentValue && !isLeft)
                return false;
            if (root->left)
            {
                if (root->left->val >= root->val)
                    return false;
                bool ret = true;
                front_traversal(root, parentValue, isLeft, ret);
                if (!ret)
                    return false;
                if (!checkSubTree(root->left, root->val, true))
                    return false;
            }
            if (root->right)
            {
                if (root->right->val <= root->val)
                    return false;
                bool ret = true;
                front_traversal(root, parentValue, isLeft, ret);
                if (!ret)
                    return false;
                if (!checkSubTree(root->right, root->val, false))
                    return false;
            }
        }
        return true;
    }
    bool validateBST(TreeNode* node, long min, long max)
    {
        if(!node)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        return validateBST(node->left, min, node->val) && validateBST(node->right, node->val, max);
    }

public:
    bool isValidBST1(TreeNode* root)
    {
        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidBST2(TreeNode* root) {
        bool retl = true, retr = true;
        if (root)
        {
            if (root->left)
                retl = checkSubTree(root->left, root->val, true);
            if (root->right)
                retr = checkSubTree(root->right, root->val, false);
        }
        return retl && retr;
    }
};

int main(void)
{
    return 0;
}
