class GoUpstairs {
public:
    GoUpstairs(){
        memset(store, 0, sizeof(store));
    }
    int countWays(int n) {
        if(store[n] != 0)
            return store[n];
        if(n == 0)
            return 0;
        else if(n == 1)
            return 0;
        else if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        int step = (countWays(n-1) + countWays(n-2))%1000000007;
        store[n] = step;
        return step;
    }
private:
    int store[100];
};
