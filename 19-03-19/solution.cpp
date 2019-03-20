class Robot {
public:
    int countWays(std::vector<std::vector<int>> map, int x, int y) {
    // write code here
    if(!map[0][0] || !map[x-1][y-1]){
        return 0;
    }
    std::vector<int> temp1(y+1,0);
    std::vector<std::vector<int>> temp(x+1,temp1);
        for(int i=x; i>=1; i--){
            if(!map[i-1][y-1]){
                break;
            }
            temp[i][y] = 1;
        }
        for(int j=y; j>=1; j--){
            if(!map[x-1][j-1]){
                break;
            }
            temp[x][j] = 1;
        }
    for(int i=x-1; i>=1; i--){
        for(int j=y-1; j>=1; j--){
            if(!map[i-1][j-1]){
                temp[i][j] = 0;
                continue;
            }
            if(i==x || j==y){
                temp[i][j] = 1;
                continue;
            }
            temp[i][j] = (temp[i+1][j] + temp[i][j+1]) % 1000000007;
        }
    }

    return temp[1][1];
    }
};
