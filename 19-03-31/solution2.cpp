class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if(S.length()==0 || L.size()==0){
            return ret;
        }
        unordered_map<string, int> L_map;
        for(const auto &l : L){
            if(L_map.find(l) == L_map.end()){
                L_map[l] = 1;
            } else {
                L_map[l] = L_map[l]+1;
            }
        }
        
        int len = L[0].size();
        for(int j=0;j<len;j++){
            unordered_map<string, int> current_map;
            int start = j;
            int count = 0;
            for(int i=j; i<S.length()-len;i=i+len){
                string sub = S.substr(i,len);
                if(L_map.find(sub)!=L_map.end()){
                    if(current_map.find(sub)==current_map.end()){
                        current_map[sub] = 1;
                    } else {
                        current_map[sub] += 1;
                    }
                    count++;
                    while(current_map[sub]>L_map[sub]){
                        string left = S.substr(start,len);
                        current_map[left] -= 1;
                        start += len;
                        count--;
                    }
                    if(count == L.size()){
                        ret.push_back(start);
                        string left = S.substr(start,len);
                        current_map[left] -= 1;
                        start += len;
                        count--;
                    }
                } else {
                    current_map.clear();
                    start = i+len;
                    count = 0;
                }
            }
        }
        return ret;
    }
};
