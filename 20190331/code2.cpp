class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int subLength = L[0].size();
        int vecLength = L.size();
        int lengthSum = S.length();
        map<string,int> words;
        for(string word : L)
        {
            words[word] ++;
        }
        
        vector<int> index;
        for(int i =0; i< lengthSum +1 - vecLength*subLength; i++)
        {
            map<string,int> temp = words;
            int j =0;
            for(; j<vecLength ;j++ )
            {
                string subOfS;
                subOfS = S.substr(i+j*subLength, subLength);
                if(words.find(subOfS)!= words.end())
                {
                    temp[subOfS]--;
                    if(temp[subOfS]<0) break;
                }
                else break;
            }
            if(j == vecLength) index.push_back(i);
        }
       return index;
    }
};