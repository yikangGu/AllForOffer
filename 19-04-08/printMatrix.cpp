class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int m,n,cir;
        m = matrix.size();
        n = matrix[0].size();
        cir = ((m<n?m:n)-1)/2+1;
         for(int i=0;i<cir;i++)
         {
            for(int j=i;j<n-i;j++)
                result.push_back(matrix[i][j]);
 
            for(int k=i+1;k<m-i;k++)
                result.push_back(matrix[k][n-1-i]);
 
            for(int l=n-2-i;l>=i&&i<m-1-i;l--)
                result.push_back(matrix[m-1-i][l]);
 
            for(int p=m-2-i;p>i&&i<n-1-i;p--)
                result.push_back(matrix[p][i]);
        }
        return result;
    }
};