/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        travel(root, sum, false);
        return sum;
    }

private:
    void travel(TreeNode *node, int &sum, bool isLeft)
    {
        if (!node)
            return;

        if (isLeft && !node->left && !node->right)
        {
            sum += node->val;
            return;
        }
           
        travel(node->left, sum, true);
        travel(node->right, sum, false);
    }
};

//[0,2,4,1,null,3,-1,5,1,null,6,null,8] expected 5
// @lc code=end

