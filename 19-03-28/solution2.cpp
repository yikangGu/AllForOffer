#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
using namespace std;
int main(){

    string temp;
    bool yes;
    while(cin >> temp){
        yes = true;
        queue<char> temp2;
        for(const auto& c : temp){
            if(c=='.'){
                int ret=0;
                string temp4;
                while(!temp2.empty()){
                    char temp3 = temp2.front();
                    temp2.pop();
                    temp4 += temp3;
                }
                stringstream ss;
                ss << temp4;
                ss >> ret;
                if(ret < 0 || ret > 255){
                    yes=false;
                }
            } else {
                temp2.push(c);
            }
        }

        int ret=0;
        string temp4;
        while(!temp2.empty()){
            char temp3 = temp2.front();
            temp2.pop();
            temp4 += temp3;
        }
        stringstream ss;
        ss << temp4;
        ss >> ret;
        if(ret < 0 || ret > 255){
            yes=false;
        }

        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
