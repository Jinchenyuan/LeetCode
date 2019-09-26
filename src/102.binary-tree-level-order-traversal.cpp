/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (false)
        {
            vector<TreeNode*> nodes;
            nodes.push_back(root);
            tarverLevel1(nodes, ans);
        }
        else
        {
            int level = 0;
            traverLevel2(root, ans, level);
        }
        return ans;
    }
    void tarverLevel1(vector<TreeNode*> levelNodes, vector<vector<int>> &ans)
    {
        if (levelNodes.size() == 0)
            return;
        vector<TreeNode*> nextNodes;
        vector<int> numVec;
        for (auto node : levelNodes)
        {
            if (node)
            {
                numVec.push_back(node->val);
                nextNodes.push_back(node->left);
                nextNodes.push_back(node->right);
            }
        }
        if (numVec.size() > 0)
            ans.push_back(numVec);
        tarverLevel1(nextNodes, ans);
    }

    void traverLevel2(TreeNode *node, vector<vector<int>> &ans, int &level)
    {
        if (!node)
            return;
        int val = node->val;
        if (ans.size() < level + 1)
        {
            vector<int> numVec;
            numVec.push_back(val);
            ans.push_back(numVec);
        }
        else
        {
            ans[level].push_back(val);
        }
        traverLevel2(node->left, ans, ++level);
        --level;
        traverLevel2(node->right, ans, ++level);
        --level;
    }
};


