class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> sum(rows, vector<int>(cols, 0));
        sum[0][0] = grid[0][0];
        for(int i = 1; i < cols; i++){
            sum[0][i] += sum[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < rows; i++){
            sum[i][0] += sum[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        return sum[rows - 1][cols - 1];
    }
};
