class Robot {
public:
    int ways(vector<vector<int> >& map, int x, int y, vector<vector<int> >& record){
        if(map[x][y] != 1)
            return 0;
        if(x + y == 0)
            return 1;
        if(x == 0)
            return ways(map, x, y-1, record);
        else if(y == 0)
            return ways(map, x-1, y, record);
        if(record[x][y]>=0)
            return record[x][y];
        int w1 = (map[x-1][y] != 1) ? 0 : ways(map, x-1, y, record);
        int w2 = (map[x][y-1] != 1) ? 0 : ways(map, x, y-1, record);
        record[x][y] = w1+w2;
        return w1+w2;
    }
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<int> > record;
        for(int i = 0; i < x; i++){
            vector<int> tmp;
            for(int j = 0; j < y; j++){
                tmp.emplace_back(-1);
            }
            record.emplace_back(tmp);
        }
            
        return ways(map, x-1, y-1, record);
    }
};
