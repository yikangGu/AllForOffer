    vector< vector<int> > result;
    vector<int> elem;

    void dfs(TreeNode* root, int expectNum) {
        elem.push_back(root->val);
        if(root->val == expectNum && root->left == NULL && root->right == NULL) {
            result.push_back(elem);
        } else {
            if(root->left) {
                dfs(root->left, expectNum - root->val);
            }
            if(root->left) {
                dfs(root->right, expectNum - root->val);
            }
        }
        elem.pop_back();
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root){
            dfs(root, expectNumber);
        }
        return result;
    }
