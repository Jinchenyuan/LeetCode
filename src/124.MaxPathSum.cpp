#include <iostream>
#include <limits.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int dfs(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return INT_MIN;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        int path = root->val + max((l >= 0 ? l : 0), (r >= 0 ? r : 0));
        ans = max(ans, path);
        int rooted = root->val + (l >= 0 ? l : 0) + (r >= 0 ? r : 0);
        ans = max(ans, rooted);
        ans = max(ans, root->val);
        return path;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        if (root == NULL)
            return ans;
        dfs(root, ans);
        return ans;
    }
};