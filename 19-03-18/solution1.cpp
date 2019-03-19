class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = INT_MAX;
        for (const auto num : nums) {
            ret = min(ret, num);
        }
        return ret;
    }
};
