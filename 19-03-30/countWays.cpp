class GoUpstairs {
public:
    int countWays(int n) {
        int a = 1;
        int b=1;
        if(n ==2)
            return 1;
        for(int i = 3; i <= n; i++)
        {
            int res = (a+b)% 1000000007;
            a = b;
            b = res;
        }
         
        return b;
    }
};
