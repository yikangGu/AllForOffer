class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> paths;
        vector<int> path;
        if(root)
            dfs(root,expectNumber,paths,path);
        return paths;
    }
    void dfs(TreeNode* root,int expectNumber,vector<vector<int>> &paths,vector<int> path){
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val==expectNumber)
                paths.push_back(path);
        }
        if(root->left)
            dfs(root->left,expectNumber-root->val,paths,path);
        if(root->right)
            dfs(root->right,expectNumber-root->val,paths,path);
        path.pop_back();
        
    }
};