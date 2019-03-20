#include <iostream>
#include <string>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

int match(string pre, string candidate, bool bFirst){
    int s = 1;
    if(bFirst)
        s = 0;
    for(int i = pre.length()-1; i>=s; i--){
        if(pre.substr(i, pre.length()-i) == 
           candidate.substr(0, pre.length()-i)){
            cout<<pre<<" : "<<candidate<<endl;
            return pre.length() - i;
        }
        if((pre.length()-i) == (candidate.length()-s))
            break;
    }
    return 0;
}

void findNextWord(string previous, vector<pair<int, string> > words, int length, vector<int>& lengths, bool bFirst){
    bool bFind = 0;
    for(auto& tmp : words){
        if(tmp.first < 2){
            int n = 0;
            n = match(previous, tmp.second, bFirst);
            if(n > 0){
                //length += (tmp.second.length() - n);
                bFind = 1;
                tmp.first++;//使用次数+1
                findNextWord(tmp.second, words, length + (tmp.second.length() - n), lengths, false);
                tmp.first--;//使用完之后回溯
            }
        }
    }
    //如果找不到了
    if(!bFind){
        lengths.emplace_back(length);
        return;
    }
}

int main(int argc, char** argv){
    int N = 0;
    cin>>N;
    vector<pair<int, string> > words;
    string word;
    for(int i = 0; i < N; i++){
        cin>>word;
        words.emplace_back(make_pair(0, word));
    }
    string begin;
    cin>>begin;
    int length = 1;
    vector<int> lengths;
    findNextWord(begin, words, length, lengths, true);
    sort(lengths.begin(), lengths.end());
    cout<<lengths.back()<<endl;
}
