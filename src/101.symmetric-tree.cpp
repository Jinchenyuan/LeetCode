#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Node
    {
        int val;
        int dir;
        Node(int ival, int idir){
            val = ival;
            dir = idir;
        }
    };

private:
    void traversalLeft(TreeNode* root, vector<struct Node> &ret, int dir)
    {
        if (root)
        {
            traversalLeft(root->left, ret, 0);
            ret.push_back(Node(root->val, dir));
            traversalLeft(root->right, ret, 1);
        }
    }

    void traversalRight(TreeNode* root, vector<struct Node> &ret, int dir)
    {
        if (root)
        {
            traversalRight(root->right, ret, 1);
            ret.push_back(Node(root->val, dir));
            traversalRight(root->left, ret, 0);
        }
    }
    bool check(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2)
            return true;
        if (!node1 || !node2)
            return false;
        if (node1->val == node2->val)
            return check(node1->left, node2->right) && check(node2->left, node1->right);
        else
            return false;
    }

public:
    bool isSymmetric1(TreeNode* root) {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
    bool isSymmetric2(TreeNode* root) {
        vector<struct Node> retLeft;
        vector<struct Node> retRight;
        if (!root)
            return true;
        traversalLeft(root->left, retLeft, 0);
        traversalRight(root->right, retRight, 1);
        if (retLeft.size() != retRight.size())
            return false;
        for (int i = 0; i < retLeft.size(); i++)
        {
            if (!(retLeft[i].val == retRight[i].val && retLeft[i].dir != retRight[i].dir))
                return false;
        }
        return true;
    }
};

int main(void)
{
    return 0;
}
