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
    void exploreTree(vector<vector<int> >& data, int depth, TreeNode* ptr){
        if(ptr == nullptr)
            return;
        if(depth<data.size())
            data[depth].emplace_back(ptr->val);
        else{
            vector<int> tmp = {ptr->val};
            data.emplace_back(tmp);
        }
        exploreTree(data, ++depth, ptr->left);
        exploreTree(data, ++depth, ptr->right);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = 0;
        vector<vector<int> > result;
        exploreTree(result, depth, root);
        return result;
    }
};
