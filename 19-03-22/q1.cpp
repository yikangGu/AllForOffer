class Solution
{
public:
    Solution(){
        memset(myset, 256, 0);
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        myset[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0; i<s.size(); i++){
            if(myset[s[i]] == 1)
                return s[i];
        }
        return '#';
    }
private:
    char myset[256];
    string s;
};
