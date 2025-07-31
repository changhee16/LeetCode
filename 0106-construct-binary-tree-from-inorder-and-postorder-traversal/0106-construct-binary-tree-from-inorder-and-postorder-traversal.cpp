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
    map<int, int> mp;
    TreeNode* help(vector<int>& inorder, vector<int>& postorder, int &postorder_idx, int inorderstart,  int inorderend)
    {
        if (inorderstart > inorderend || postorder_idx < 0)
            return nullptr;
        int root_val = postorder[postorder_idx--];
        TreeNode* root = new TreeNode(root_val);
        int pose = mp[root_val];
        root->right = help(inorder,postorder, postorder_idx, pose + 1, inorderend);
        root->left = help(inorder,postorder, postorder_idx, inorderstart, pose - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        int postorder_idx = postorder.size() - 1;
        return help(inorder, postorder, postorder_idx, 0, inorder.size() - 1);
    }
};