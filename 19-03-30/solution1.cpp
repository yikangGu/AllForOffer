class GoUpstairs {
public:
    int countWays(int n) {
        // write code here
        vector<int> temp;
        temp.assign(n,0);
        temp[0] = 1;
        temp[1] = 1;
        if(n<2){
            return temp[n-1];
        }
        for(int i = 2; i<n; i++){
            temp[i] = (temp[i-2] + temp[i-1])%1000000007;
        }
        return temp[n-1];
    }
};
