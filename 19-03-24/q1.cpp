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
    bool isSymmetric(TreeNode* p1, TreeNode* p2){
        if(p1 == nullptr && p2 == nullptr)
            return true;
        else if(p1 != nullptr && p2 != nullptr){
            if(p1->val == p2->val){
                return isSymmetric(p1->left, p2->right) && isSymmetric(p1->right, p2->left);
            }
            else
                return false;
        }
        else
            return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
