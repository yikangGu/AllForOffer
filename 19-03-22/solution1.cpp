class Solution
{
public:
    unordered_map<char, int> char_cnt;
    string s; 
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(char_cnt.find(ch) == char_cnt.end()){
             char_cnt[ch] = 1;
         } else {
             char_cnt[ch] += 1;
         }
         s = s+ch;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(const auto c : s){
            if(char_cnt[c]==1){
                return c;
            } else {
                continue;
            }
        }
        return '#';
    }

};
