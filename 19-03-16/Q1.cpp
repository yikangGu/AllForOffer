/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root) return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> path;
        int currSum = 0;
        findPath(root, path, currSum, expectNumber, res);
        return res;
    }
    void findPath(TreeNode* root, vector<int>& path, int currSum, int expectNumber, vector<vector<int>>& res){
        if(!root) return;
        path.push_back(root->val);
        currSum += root->val;
        
        if(!root->left && !root->right && currSum == expectNumber){
            res.push_back(path);
        }
        
        if(root->left)
            findPath(root->left, path, currSum, expectNumber, res);
        if(root->right)
            findPath(root->right, path, currSum, expectNumber, res);
        path.pop_back();
    }
};
