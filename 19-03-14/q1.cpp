#include <iostream>

using namespace std;

bool match(string& str, string& pat, int p1, int p2){
  if(p2 == 0 && pat[p2] == '*'){
    cerr<<"Error of pattern!"<<endl;
    return 0;
  }  

  if(str[p1] == pat[p2]){
    cout<<"1"<<endl;
    if(str[p1] == '\0')
      return 1;
    ++p1;
    ++p2;
    return match(str, pat, p1 ,p2);
  }
  else if(pat[p2] == '.'){ 
    cout<<"2"<<endl;
    if(str[p1] == '\0')
      return 0;
    pat[p2] = str[p1];
    ++p1;
    ++p2;
    return match(str, pat, p1, p2);
  }
  else if(pat[p2+1] == '*'){
    cout<<"3"<<endl;
    p2 = p2+2;
    return match(str, pat, p1, p2);
  }
  else if(pat[p2] == '*'){ 
    cout<<"4"<<endl;
    if(pat[p2-1] == str[p1]){
      ++p1;
      return match(str, pat, p1, p2);
    }
    else{
      ++p2;
      return match(str, pat, p1, p2);
    }
  }
  else{
    cout<<"5"<<endl;
    return 0;
  }
}

int main(int argc, char** argv){
  string str, pattern;
  cin>>str>>pattern;
 
  if(match(str, pattern, 0, 0))
    cout<<"true"<<endl;
  else
    cout<<"false"<<endl;
  
  return 0;
}
