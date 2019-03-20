#include <iostream>
#include <vector>    
#include <list>
using namespace std;

    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        list<int> maxQueue;
        for(unsigned int i = 0; i < num.size(); i++){
            while (maxQueue.size() && (maxQueue.front()+size <= i)){
                maxQueue.pop_front();
            }
            while(!maxQueue.empty() && (num[maxQueue.back()] <= num[i])){
                maxQueue.pop_back();
            }
            maxQueue.push_back(i);
            for(auto iter = maxQueue.begin(); iter != maxQueue.end(); iter++)
                cout<<*iter;
            cout<<endl;
            if(size && i>=size-1)
                result.emplace_back(num[maxQueue.front()]);
        }
        return result;
    }

int main(){
  vector<int> result;
  vector<int> data = {1,3,-1,-3,5,3,6,7};
  result = maxInWindows(data, 3);
  cout<<"result"<<endl;
  for(auto tmp : result){
    cout<<tmp<<endl;
  }
  //cout<<result<<endl;
}
