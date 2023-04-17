/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
/**
 *  */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes1(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == right)
        {
            return (1 << left) + countNodes1(root->right);
        }
        return (1 << right) + countNodes1(root->left);
    }

    int countNodes2(TreeNode *root)
    {
        int countNum = 0;
        countNodes(root, countNum);
        return countNum;
    }

private:
    int depth(TreeNode *root)
    {
        int d = 0;
        for (; root; root = root->left)
        {
            ++d;
        }
        return d;
    }

    void countNodes(TreeNode *node, int &countNum)
    {
        if (!node)
        {
            return;
        }
        countNum++;
        countNodes(node->left, countNum);
        countNodes(node->right, countNum);
    }
};
// @lc code=end
