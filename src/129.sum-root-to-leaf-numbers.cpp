/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_v(vector<int> v)
{
    cout << "[";
    for (size_t k = 0; k < v.size(); k++)
    {
        if (k != v.size() - 1)
            cout << v[k] << ", ";
        else
            cout << v[k];
    }
    cout << "]" << endl;
}

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return calculateNode(root, 0);
    }

private:
    int calculateNode(TreeNode *node, int sumValue)
    {
        if (node == NULL)
        {
            return 0;
        }
        sumValue = sumValue * 10 + node->val;
        if (node->left == NULL && node->right == NULL)
        {
            return sumValue;
        }
        return calculateNode(node->left, sumValue) + calculateNode(node->right, sumValue);
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution s;
    cout << s.sumNumbers(root) << endl;
    return 0;
}
// @lc code=end
