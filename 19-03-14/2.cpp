#include <vector>
#include <iostream>

using namespace std;

string LPD(string s)
{
    vector<vector<bool>> map = {{0}};
    for(size_t i = 0; i < s.size(); i++)
        for(size_t j = i + 1; j < s.size(); j++)
            if (s[i] == s[j]) map[i][j] == true;
    map.begin()
}

int main(int argc, char const *argv[])
{
    cout << " 1: " << LPD("aa") << endl;
    cout << " 2: " << LPD("aa") << endl;
    return 0;
}
