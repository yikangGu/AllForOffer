class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int l = 1, r = 1;
        vector<int> left = {1};
        vector<int> right = {1};
        for(int i = 0; i < A.size()-1; i++){
            l *= A[i];
            left.emplace_back(l);
            r *= A[A.size()-1-i];
            right.emplace_back(r);
        }
        vector<int> result;
        for(int i = 0; i < A.size(); i++){
            result.emplace_back(left[i] * right[A.size()-1-i]);
        }
        return result;
    }
};
