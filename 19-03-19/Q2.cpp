class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        // write code here
        if(x < 1 || y < 1) return 0;
        if(map[0][0] == 0) return 0;
        vector<vector<int>> res(x, vector<int>(y, 0));
        for(int i = 0; i < x; i++){
            if(map[i][0] == 1)
                res[i][0] = 1;
            else
                break;
        }
        for(int i = 1; i < y; i++){
            if(map[0][i] == 1)
                res[0][i] = 1;
            else
                break;
        }
        for(int i = 1; i < x; i++){
            for(int j = 1; j < y; j++){
                if(map[i][j] == 1)
                    res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[x-1][y-1]%1000000007;
    }
};
