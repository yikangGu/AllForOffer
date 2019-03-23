class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        for(int i = 0; i < A.size(); i++)
        {
            int tmp = 1;
            for(int j = 0; j < A.size(); j++)
            {
                if( j != i)
                    tmp = tmp * A[j];
                else
                    continue;
            }
            
            B.push_back(tmp);
        }
    return B;
    }
};