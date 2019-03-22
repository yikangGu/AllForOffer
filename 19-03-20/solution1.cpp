class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res(A.size(), 1);
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A.size(); j++){
                if(j==i)
                    continue;
                res[j] = res[j]*A[i];
            }
        }
        return res;
    }
};
