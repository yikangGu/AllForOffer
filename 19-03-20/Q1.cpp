class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        for(int i = 1; i < A.size(); i++){
            B[i] = A[i-1] * B[i-1];
        }
        int temp = 1;
        for(int i = A.size() - 1; i >= 0; i--){
            B[i] *= temp;
            temp *= A[i];
        }
        return B;
    }
};
