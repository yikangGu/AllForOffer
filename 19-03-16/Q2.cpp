#include <iostream>
#include <vector>

using namespace std;
int length = 0;

int compare(string str1, string str2) {
    for(int i = 1; i <= min(str1.size(), str2.size()); i++) {
        int flag = 1;
        for(int j = 0; j < i; j++)
            if(str1[str1.size() - i + j] != str2[j]) flag = 0;
        if(flag) return i;
    }
    return 0;
}

void solve(string strnow, int lengthnow, vector<string> words, vector<int>& repeat) {
    length = max(lengthnow, length);
    for(int i = 0; i < words.size(); i++) {
        if(repeat[i] >= 2) continue;
        int c = compare(strnow, words[i]);
        if(c > 0) {
            repeat[i]++;
            solve(words[i], lengthnow + words[i].size() - c, words, repeat);
            repeat[i]--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    string temp;
    vector<string> words;
    for(int i = 0; i < n; i++){
        cin>>temp;
        words.push_back(temp);
    }
    string key_ch;
    cin>>key_ch;
    vector<int> repeat(words.size(), 0);
    solve(key_ch, 1, words, repeat);
    cout<<length<<endl;
}
