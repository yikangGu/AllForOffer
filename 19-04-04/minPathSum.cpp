class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int **dp = new int*[m];
        for(int i=0; i<m; i++)
            dp[i] = new int[n];
        dp[0][0] = grid[0][0];
        
        for(int i=1; i<m;i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        for(int j=1; j<n; j++)
            dp[0][j] = grid[0][j] + dp[0][j-1];
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(dp[i-1][j] <= dp[i][j-1])
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                
            }
        }
        
        return dp[m-1][n-1];
    }
};