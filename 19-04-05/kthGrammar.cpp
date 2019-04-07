class Solution {
public:
    int kthGrammar(int N, int K) {
        int result = 0;
        if(N==1)
            return 0;
        if(K%2==0)
            result = !kthGrammar(N-1,K/2);
        else
            result = kthGrammar(N-1,K/2+1);
        return result;
    }
};