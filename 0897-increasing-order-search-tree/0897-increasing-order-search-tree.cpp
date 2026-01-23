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
    TreeNode* new_node = nullptr;
    TreeNode* curr = nullptr;

    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        root->left = nullptr;
        if (!new_node)
        {
            new_node = root;
            curr = new_node;
        }
        else
        {
            curr->right = root;
            curr = curr->right;
        }
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return new_node;
    }
};