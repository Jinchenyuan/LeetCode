#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void back_traversal(TreeNode* root, vector<int> &ret)
    {
        if (root)
        {
            back_traversal(root->left, ret);
            back_traversal(root->right, ret);
            ret.push_back(root->val);
        }
    }

    void front_traversal(TreeNode* root, vector<int> &ret)
    {
        if (root)
        {
            ret.push_back(root->val);
            front_traversal(root->left, ret);
            front_traversal(root->right, ret);
        }
    }

    void middle_traversal(TreeNode* root, vector<int> &ret)
    {
        if (root)
        {
            middle_traversal(root->left, ret);
            ret.push_back(root->val);
            middle_traversal(root->right, ret);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        middle_traversal(root, ret);
        return ret;
    }
};

int main(void)
{
    return 0;
}
