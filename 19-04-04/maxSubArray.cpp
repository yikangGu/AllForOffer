class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int m = nums.size();
        int *dp = new int[m];
        int result = nums[0];
        dp[0] = nums[0];
        for(int i=1; i<m; i++)
        {
            if(dp[i-1]+nums[i] > nums[i])
                dp[i] = dp[i-1]+nums[i];
            else
                dp[i] = nums[i];
        }
        
        for(int i=0; i<m; i++)
        {
            if(dp[i]>result)
                result = dp[i];
        }
        return result;
    }
};