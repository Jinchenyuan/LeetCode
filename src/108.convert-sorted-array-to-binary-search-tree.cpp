/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelTraverse(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode> queue;
    queue.push(*root);
    while (!queue.empty())
    {
        TreeNode node = queue.front();
        cout << node.val << "  ";
        if (node.left)
        {
            queue.push(*node.left);
        }
        if (node.right)
        {
            queue.push(*node.right);
        }
        queue.pop();
    }
}

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildTree(0, nums.size() - 1, nums);
    }

    TreeNode *buildTree(int left, int right, vector<int> &nums)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        TreeNode *leftNode = buildTree(left, mid - 1, nums);
        TreeNode *rightNode = buildTree(mid + 1, right, nums);
        return new TreeNode(nums[mid], leftNode, rightNode);
    }
};

int main(int argc, char **argv)
{
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    Solution s;
    TreeNode *node = s.sortedArrayToBST(nums);
    levelTraverse(node);
    return 0;
}
// @lc code=end
