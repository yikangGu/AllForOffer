#include <iostream>

using namespace std;

bool isTrue(string& A, int start, int end, int n, int* record){
  if(record[start*n+end] == 1)
    return true;
  if(start >= end)
    return true;
  if(A[start] == A[end])
    if(isTrue(A, start+1, end-1, n, record)){
      record[start*n+end] = 1;
      cout<<start<<", "<<end<<": is true"<<endl;
      return true;
    }
  return false;
}

int getLongestPalindrome(string A, int n) {
  int* record = new int[n*n]{0};
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++){
      int f = isTrue(A, i, j, n, record);
      if(i==1 && j ==5)
        cout<<i<<", "<<j<<": "<<f<<endl;
    }
  int max = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      int len = 0;
      if(record[i*n+j])
	len = j - i;
	max = (len > max) ? len : max;
    }
  delete []record;
  return max+1;
}

int main(int argc, char** argv){
  string A = "abc1234321ab";
  int result = getLongestPalindrome(A, 12);
  cout<<"result: "<<result<<endl;
}
