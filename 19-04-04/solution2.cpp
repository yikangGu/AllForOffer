class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int f[nums.size()+1];
        f[0]=0;
        int max_res = -INT_MAX;
        for(int i=1;i<=nums.size();i++){
            f[i] = max(f[i-1]+nums[i-1], nums[i-1]);
            max_res = max(max_res,f[i]);
            //cout<<f[i]<<endl;
        }
        return max_res;
    
    }
};
