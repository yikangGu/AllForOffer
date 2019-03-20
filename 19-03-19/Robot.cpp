class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        int **dp = new int* [x];
        for(int i = 0; i < x; i++)
            dp[i] = new int [y];
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i < x; i++)
        {
            if(map[i][0] != 1)
                break;
            dp[i][0] = 1;
        }
        for(int i = 0; i < y; i++)
        {
            if(map[0][i] != 1)
                break;
            dp[0][i] = 1;
        }
        for(int i = 1; i < x; i++)
        {
            for(int j = 1; j < y; j++)
            {
                if(map[i][j] == 1)
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
        return dp[x-1][y-1];
    }
};