/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetricUtil(TreeNode* left, TreeNode* right) {
        if(left==right) {
            return true;
        } else if(left == NULL | right == NULL) {
            return false;
        } else if(left->val != right->val) {
            return false;
        }
        return isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left); 
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        } else {
            return isSymmetricUtil(root->left, root->right); 
        }
    }

};
