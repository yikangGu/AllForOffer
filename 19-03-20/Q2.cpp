class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0 || num.size() == 1) return num.size(); 
        unordered_set<int> set(num.begin(), num.end());
        
        int res = 0;
        for(int i = 0; i < num.size(); i++){
            int prev = num[i];
            int next = num[i];
            while(set.count(--prev)){
                set.erase(prev);
            }
            while(set.count(++next)){
                set.erase(next);
            }
            res = max(res, next - prev - 1);
        }
        return res;
    }
};
