class Solution {
public:
    int findMin(vector<int>& nums, int left, int right){
        if(left == right)
            return nums[left];
        if(abs(left - right) < 2)
            return min(nums[left], nums[right]);
        if(nums[(left+right)/2] >= nums[left]){
            left = (left+right)/2;
            return findMin(nums, left, right);
        }
        else {
            right = (left+right)/2;
            return findMin(nums, left, right);
        }
    }
    
    int findMin(vector<int>& nums) {
        if(nums.front() < nums.back())
            return nums.front();
        int left = 0, right = nums.size()-1;
        return findMin(nums, left, right);
    }
};
