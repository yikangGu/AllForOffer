#include <vector>
#include <iostream>

using namespace std;

bool cmp(char x, char y)
{
    return x == y || y == '.';
}

bool isMatch(string s, string p)
{
    int idx = 0;
    for (size_t i = 0; i < p.size(); i++)
    {
        if (s[0] == p[i] || s[0] == '.')
        {
            idx = i;
            break;
        }
    }

    int s_idx = 1;
    bool flag = false;
    for (size_t i = idx + 1; i < p.size(); i++)
    {
        if (p[i] == '*')
        {
            if (cmp(s[s_idx], p[i - 1]))
            {
                while (s_idx < s.size() - 1)
                {
                    flag = true;
                    if (s[s_idx] == s[s_idx + 1] || p[i - 1] == '.')
                        s_idx++;
                    else
                    {
                        i++;
                        s_idx++;
                        break;
                    }
                }
            }
            else
                return false;
        }

        if (cmp(s[s_idx], p[i]) && flag == true)
            s_idx++;
        else if (cmp(s[s_idx], p[i - 1]) && flag == false)
            return true;
        else
            return false;
    }

    if (s_idx != s.size())
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    cout << " 1: " << isMatch("aa", "a") << endl;
    cout << " 2: " << isMatch("aa", "a*") << endl;
    cout << " 3: " << isMatch("ab", ".*") << endl;
    cout << " 4: " << isMatch("aaaaaab", "c*a*b") << endl;
    cout << " 5: " << isMatch("mississippi", "mis*is*p*.") << endl;
    return 0;
}
