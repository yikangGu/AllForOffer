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

bool match(string &str, string &pat, int p1, int p2)
{
    if (p2 == 0 && pat[p2] == '*')
    {
        cerr << "Error of pattern!" << endl;
        return 0;
    }

    if (str[p1] == pat[p2])
    {
        cout << "1" << endl;
        if (str[p1] == '\0')
            return 1;
        ++p1;
        ++p2;
        return match(str, pat, p1, p2);
    }
    else if (pat[p2] == '.')
    {
        cout << "2" << endl;
        if (str[p1] == '\0')
            return 0;
        pat[p2] = str[p1];
        ++p1;
        ++p2;
        return match(str, pat, p1, p2);
    }
    else if (pat[p2 + 1] == '*')
    {
        cout << "3" << endl;
        p2 = p2 + 2;
        return match(str, pat, p1, p2);
    }
    else if (pat[p2] == '*')
    {
        cout << "4" << endl;
        if (pat[p2 - 1] == str[p1])
        {
            ++p1;
            return match(str, pat, p1, p2);
        }
        else
        {
            ++p2;
            return match(str, pat, p1, p2);
        }
    }
    else
    {
        cout << "5" << endl;
        return 0;
    }
}

// def isMatch(s, p):
//     if p == "":
//         return s == ""
//     if len(p) > 1 and p[1] == "*":
//         return isMatch(s, p[2:]) or (s and (s[0] == p[0] or p[0] == '.') and isMatch(s[1:], p))
//     else:
//         return s and (s[0] == p[0] or p[0] == '.') and isMatch(s[1:], p[1:])
