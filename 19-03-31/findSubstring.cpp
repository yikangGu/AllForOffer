class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> counts;
        for (int i = 0; i < L.size(); i++)
            counts[L[i]]++;
        int n = S.length(), num = L.size(), len = L[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) 
        {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) 
            {
                string word = S.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) 
                {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) 
                indexes.push_back(i);
        }
        return indexes;
    }
};