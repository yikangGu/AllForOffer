#include "bits/stdc++.h"
using namespace std;

/*求最大公约数*/
int greatestCommonDivisor(int a, int b){
    while(a != b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    return b;
}

/*打怪过程*/
void fighting(int& power, int defense){
    if(defense <= power)
        power += defense;
    else{
        power += greatestCommonDivisor(power, defense);
    }
}

int main(int argc, char** argv){
    /*输入参数*/
    vector<int> data;
    int num_beast = 0, power = 0, defense = 0;
    while(cin>>num_beast>>power){
        for(int i = 0; i < num_beast; i++){
            cin>>defense;
            fighting(power, defense);
        }
        cout<<power<<endl;
    }
}
