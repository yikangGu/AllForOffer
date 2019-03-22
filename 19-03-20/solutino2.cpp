class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        sort(num.begin(), num.end());
        int ret=1,temp=1,last=INT_MIN;
        for(const auto n : num) {
            if(n-last==1){
                temp++;
                ret = max(ret, temp);
            } else if(n==last){
                continue;
            } else {
                temp = 1;
            }
            last = n;
        }
        return ret;
    }
};
