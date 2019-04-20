#include <vector>
#include <iostream>

using namespace std;

string LPD(string s)
{
    if (s.size() == 0)
        return s;
    vector<bool> row(s.size());
    vector<vector<bool> > map(s.size(), row);
    int left = 0;
    int right = 0;
    for (size_t i = s.size() - 2; i > 0; i--)
    {
        for (size_t j = i + 1; j < s.size(); j++)
        {
            map[i][j] = s[i] == s[j] && (j - i < 3 || map[i + 1][j - 1]);
            if (map[i][j] && j - i > right - left)
            {
                left = i;
                right = j;
            }
        }
    }

    return s.substr(left, right - left + 1);
}

int main(int argc, char const *argv[])
{
    cout << " 1: " << LPD("babac") << endl;
    cout << " 2: " << LPD("fvasdfdsaabi") << endl;
    return 0;
}
