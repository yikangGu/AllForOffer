class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNumber = -1;
        if(nums.size() == 0)
            minNumber = -1;
        else if(nums.size() == 1)
            minNumber = nums[0];
        else
        {
            int index;
            bool judge = 0;
            for(int i = 0; i < nums.size() - 1; i++)
            {
                if(nums[i] > nums[i + 1])
                {
                    index = i;
                    judge = 1;
                    break;
                }
            }
            if(judge)
            {
                if(nums[index] > nums[0])
                    minNumber = nums[0];
                else
                    minNumber = nums[index];
            }
            else
                minNumber = nums[0];
        }
        return minNumber;
    }
};