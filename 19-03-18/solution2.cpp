class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        vector<int> res;
        for(const auto num : nums1) {
            record[num]++;
        } 
        for(const auto num : nums2) {
            if(record[num]>0) {
                res.push_back(num);
                record[num]--;
            }
        }
        return res;
    }
};
