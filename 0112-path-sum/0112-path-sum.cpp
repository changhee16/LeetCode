/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, int curSum, int targetSum)
    {
        if (!root->left && !root->right)
            return (curSum == targetSum);
        bool found = false;
        if (root->left)
            found = dfs(root->left, curSum + root->left->val, targetSum);
        if (!found && root->right)
            found = dfs(root->right, curSum + root->right->val, targetSum);
        return found;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        else
            return dfs(root, root->val, targetSum);
    }
};