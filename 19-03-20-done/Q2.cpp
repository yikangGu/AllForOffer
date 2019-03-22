class Solution {
public:
    int longestConsecutive(vector<int> &num) {
            unordered_set<int> st(num.begin(),num.end());
            int ans=0;
            for(auto v:num){
                if(st.find(v)==st.end()) continue;
                int l=v,r=v;
                st.erase(v);
                while(st.find(r+1)!=st.end()) st.erase(++r);
                while(st.find(l-1)!=st.end()) st.erase(--l);
                ans=max(r-l+1,ans);
            }
            return ans;
    }
};