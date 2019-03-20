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
    bool findNextNode(TreeNode* root, int expectNumber, vector<int> path, vector<vector<int> >& paths)  {
      if(root == nullptr)
        return false;
      if(root->val > expectNumber)
        return false;
      if(root->val == expectNumber){
        if(root->left == nullptr || root->right == nullptr){
          path.emplace_back(root->val);
          paths.emplace_back(path);
          return true;
        }
        else
          return false;
      }
      path.emplace_back(root->val);
      int expectNumberNew = expectNumber - root->val;
      bool left = findNextNode(root->left, expectNumberNew, path, paths);
      bool right = findNextNode(root->right, expectNumberNew, path, paths);
      return( left || right);
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      vector<vector<int> > paths;
      vector<int> path;
      if(root == nullptr)
        return paths;
      if(findNextNode(root, expectNumber, path, paths)){
        pair<int, vector<int> > path_pair;
        vector<pair<int, vector<int> > > paths_pair;
        for(auto& tmp : paths){
          path_pair.first = tmp.size();
          path_pair.second = tmp;
          paths_pair.emplace_back(path_pair);
        }
        sort(paths_pair.begin(), paths_pair.end(), 
             [](const pair<int, vector<int> > a, const pair<int, vector<int> > b)
             {return a.first > b.first;});
        vector<vector<int> > result;
        for(auto& tmp : paths_pair) {
          result.emplace_back(tmp.second);
        }
        return result;
      }
      else
        return paths;
    }
};
