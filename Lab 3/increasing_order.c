/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* increasingBST(struct TreeNode* root) {
    if (!root) {
        return NULL;
    }
    
    struct TreeNode* left = increasingBST(root->left);
    struct TreeNode* right = increasingBST(root->right);
    
    root->left = NULL;
    root->right = right;
    
    if (!left) {
        return root;
    }
    
    struct TreeNode* iter = left;
    while (iter && iter->right) {
        iter = iter->right;
    }
    
    iter->right = root;
    
    return left;
}
