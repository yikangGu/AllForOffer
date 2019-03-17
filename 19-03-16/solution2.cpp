#include<iostream>
#include<cstring>

int max_len;
int vis[20];
int n;
string ins[20];
string head;

bool check(string s1, string s2, int k) {
    int len = s1.length();
    for(int i=0; i < k; i++) {
        if (s1[len - k + i] != s2[i])
            return false;
    }
    return true;
}

string add(string temp, string in, int k) {
    for(int i=k; i < in.length(); i++){
        temp += in[i];
    }
    return temp;
}

void bfs(string in){
    int len = in.length();
    max_len = max(max_len,len);
    for(int i=0; i<n;i++){
        if(vis[i]>=2) continue;
        for(int j=1; j <= ins[i].length(); j++){
            if(check(in, ins[i], j)){
                string temp = add(in, ins[i], j);
                vis[i]++;
                bfs(temp);
                vis[i]--;
            }
        }
    }
}

int main(int argc, char **argv){
    scanf("%d",&n);
    for(int i=0;i<n;++i)cin>>ins[i];
    cin>>head;
    dfs(head);
    printf("%d",max_len);
    return 0;
}
