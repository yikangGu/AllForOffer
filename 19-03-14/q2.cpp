#include <iostream>
#include <vector>

using namespace std;

int cha2id(char c){
  return int(c) - 97;
}

int main(int argc, char** argv){
  string str;
  cin>>str;
  int q = 0;
  int data[26][2];
  memset(data, -1, sizeof(data));
  while(str[q] != '\0'){
    char c = str[q];
    if(data[cha2id(c)][0] == -1)
      data[cha2id(c)][0] = q;
    data[cha2id(c)][1] = q;
    ++q;
  }
  vector< pair<int, int> > length;
  for(int i = 0; i < 26; i++){
    length.push_back(make_pair(i, data[i][1] - data[i][0]));
  }
  sort(length.begin(), length.end(), [](const pair<int, int> A, const pair<int, int> B){return A.second > B.second;});
  int id = length.front().first;
  char result[1000];
  int j = 0;
  cout<<"s: "<<data[id][0]<<" e: "<<data[id][1]<<endl;
  for(int i = data[id][0]; i <= data[id][1]; i++, j++){
    result[j] = str[i];
  }
  result[j] = '\0';
  cout<<"result: "<<result<<endl;
}
