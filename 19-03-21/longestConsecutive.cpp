class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0) 
            return 0;
        
        map<int, int> m;
        vector<int>::iterator ite = num.begin();
        vector<int>::iterator end = num.end();
        
        for(; ite != end; ++ite){
            if(m.find(*ite) == m.end())
                m.insert(pair<int, int>(*ite, 1));
        }
        
        int maxLen = 0, len = 0;
        
        for(ite = num.begin(); ite != end; ++ite)
        {
            m[*ite] = 0;
            int len = 1;
            int left = *ite - 1;
            int right = *ite + 1;
 
            while(m.find(left) != m.end() && m[left])
            {
                m[left--] = 0;
                len++;
            }
            while(m.find(right) != m.end() && m[right])
            {
                m[right++] = 0;
                len++;
            }
            if(maxLen < len) maxLen = len;
        }
        return maxLen;;
    }
};