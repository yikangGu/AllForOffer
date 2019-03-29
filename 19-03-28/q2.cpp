//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
enum State{INIT, NUMBER, POINT};

bool isNumber(char a){
    if(a >= 48 && a <= 57)
        return true;
    else
        return false;
}

int main(int argc, char** argv){
    State state;
    state = INIT;
    string str;
    cin>>str;
    int i = 0;
    int num = 0;
    int num_point = 0;
    while(str[i] != '\0'){
        switch(state){
            case INIT:
                if(isNumber(str[i])){
                    num = (int)str[i] - 48;
                    state = NUMBER;
                    break;
                }
                else{
                    cout<<"NO"<<endl;
                    return 0;
                }
            case NUMBER:
                if(isNumber(str[i])){
                    num *= 10;
                    num += (int)str[i] - 48;
                    if(num > 255){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                    break;
                }
                else if(str[i] == '.'){
                    num = 0;
                    state = POINT;
                    break;
                }
                else{
                    cout<<"NO"<<endl;
                    return 0;
                }
            case POINT:
                num_point++;
                if(isNumber(str[i])){
                    num = (int)str[i] - 48;
                    state = NUMBER;
                    break;
                }
                else{
                    cout<<"NO"<<endl;
                    return 0;
                }
        }
        i++;
    }
    if(state == NUMBER && num_point == 3){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
