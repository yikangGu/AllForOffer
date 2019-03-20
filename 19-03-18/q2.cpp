class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int data[1000] = {0};
        vector<int> result;
        for(auto tmp : nums1){
            data[tmp]++;
        }
        for(auto tmp : nums2){
            if(data[tmp]){
                result.emplace_back(tmp);
                data[tmp]--;
            }
        }
        return result;
    }
};
