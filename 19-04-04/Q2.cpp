class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for(const auto& n: nums){
            sum += n;
            if(sum > max) max = sum;
            if(sum < 0) sum = 0;
        }
        return max;
    }
};
