class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        int sums = 0;
        for(int i=0; i<nums.size(); i++)
            sums += nums[i];
        if(sums%k != 0)
            return false;
        else
        {
            vector<bool> visit(nums.size(),false);
            return canSubSets(nums,visit,sums/k,k,sums/k,0);
        }
    }
    
    bool canSubSets(vector<int>& nums, vector<bool> visit, int avg, int k, int temp, int index)
    {
        if(k==0)
            return true;
        if(temp==0)
            return canSubSets(nums,visit,avg,k-1,avg,0);
        for(int i=index; i<nums.size(); i++)
        {
            if(visit[i]==true)
                continue;
            visit[i]=true;
            if(temp-nums[i]>=0 && canSubSets(nums,visit,avg,k,temp-nums[i],index+1))
                return true;
            visit[i]=false;
        }
        return false;
    }
};