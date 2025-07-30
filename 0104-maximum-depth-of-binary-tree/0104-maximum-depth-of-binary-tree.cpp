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
    int find(TreeNode* node, int d) {
        if (node == nullptr)
            return d - 1;
        int leftNode = find(node->left, d+1);
        int rightNode = find(node->right, d+1);
        return max(leftNode, rightNode);
    }

    int maxDepth(TreeNode* root) {
        return find(root, 1);
    }
};