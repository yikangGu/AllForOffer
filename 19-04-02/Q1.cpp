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
    int kthSmallest(TreeNode* root, int& k) {
        int result = INT_MIN;
        if(root->left){
            result = kthSmallest(root->left, k);
        }
        
        if(result == INT_MIN){
            if(k == 1) result = root->val;
            k--;
        }
        
        if(result == INT_MIN && root->right){
            result = kthSmallest(root->right, k);
        }
        
        return result;
    }
};
