class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        int max = INT_MIN;
        if(size == 0 || num.size() == 0 || num.size() < size){
            return vector<int>{};
        }else{
            for(int i = 0; i <= num.size() - size; i++){
                int max = INT_MIN;
                for(int j = i; j < i + size; j++){
                    if(num[j] > max)
                        max = num[j];
                }
                res.push_back(max);
            }
        }
        return res;
    }
};
