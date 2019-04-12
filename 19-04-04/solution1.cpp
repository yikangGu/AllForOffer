class Solution {
public:
    int minPathSum(int x, int y, vector<vector<int>>& grid) {
        if(x>grid.size()-1 || y>grid[0].size()-1)
            return INT_MAX;
        if(x==grid.size()-1 && y==grid[0].size()-1)
            return grid[x][y];
        return grid[x][y] + min(minPathSum(x+1, y, grid), minPathSum(x, y+1, grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum(0, 0, grid);
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) {
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                }
                else if(j == 0) {
                    grid[i][j] += grid[i-1][j];
                }
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};
