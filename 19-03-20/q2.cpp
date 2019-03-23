class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> myset(num.begin(), num.end());
        //myset.push_back()
        int length = 1;//至少是1
        for(auto n : num){
            if(myset.find(n) == myset.end())
                continue;
            myset.erase(n);
            int f = n-1, b = n+1;
            while(myset.find(f) != myset.end())
                myset.erase(f--);
            while(myset.find(b) != myset.end())
                myset.erase(b++);
            length = max(length, b - f-1);
        }
        return length;
    }
};
