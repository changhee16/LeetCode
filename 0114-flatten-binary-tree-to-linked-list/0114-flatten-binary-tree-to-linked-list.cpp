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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return ;
        flatten(root->left);
        flatten(root->right);
        if (root->left)
        {
            TreeNode* leftsub = root->left;
            TreeNode* leftmost = leftsub;
            while(leftmost->right)
                leftmost = leftmost->right;
            leftmost->right = root->right;
            root->right = leftsub;
            root->left = nullptr;
        }
       //TreeNode* tmp = root->right;
       //cout << "tmp : " << tmp->val << "\n";
       //root->right = root->left;
       //cout << "root->right : " << root->right->val << "\n";
       //root->left = nullptr;
       //root->right->right = tmp;
       //cout << "root->right->right : " << root->right->right->val << "\n";
       //flatten(root->right); 
    }
};