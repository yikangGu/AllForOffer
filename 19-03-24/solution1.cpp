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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q1,q2;
        if(!root) {
            return res;
        }
        q1.push(root);
        while(!q1.empty()){
            vector<int> v;
            std::cout << "[";
            while(!q1.empty()){
                auto n1 = q1.front();
                q1.pop();
                v.emplace_back(n1->val);
                std::cout << n1->val << " ";
                if(n1->left){
                    q2.push(n1->left);
                }
                if(n1->right){
                    q2.push(n1->right);
                }
            }
            std::cout << "]" << std::endl;
            res.emplace_back(v);
            swap(q1,q2);
        }
        return res;
    }
};
