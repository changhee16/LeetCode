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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int root_idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        preorder.erase(preorder.begin());

        vector<int> inorder_left(inorder.begin(), inorder.begin() + root_idx);
        vector<int> inorder_right(inorder.begin() + root_idx + 1, inorder.end());

        root->left = buildTree(preorder, inorder_left);
        root->right = buildTree(preorder, inorder_right);
        return root;
    }
};