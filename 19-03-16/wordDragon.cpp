#include<iostream>
#include<cstring>

using namespace std;

struct dragon
{
    char word[10000];
    int len;
    int used;
};

struct dragon s[21];
int n;
int maxLen;

void dfs(int x, int len)
{
    int i,j;
    for(i = 1; i <= n; i++)
    {
        if(s[i].used < 2)
        for(j = 0; j < s[x].len; j++)
        {
            if(s[x].word[j] == s[i].word[0])
            {
                int a = j + 1;
                int b = 1;
                bool judge = true;
                for(;a < s[x].len && b < s[i].len; b++,a++)
                {
                    if(s[i].word[b] != s[x].word[a])
                    {
                        judge = false;
                        break;
                    }
                }
                if(judge)
                { 
                    s[i].used++;
                    dfs(i,len + s[i].len - b);
                    s[i].used--;
                }
            }
        }
    }
    if(len > maxLen)
        maxLen = len;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin>>s[i].word;
        s[i].len = strlen(s[i].word);
    }
    
    cin >> s[0].word;
    s[0].len = strlen(s[0].word);
    
    dfs(0,s[0].len);
    
    cout << maxLen;
    
    return 0;
}