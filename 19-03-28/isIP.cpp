#include<iostream>
using namespace std;
int main()
{
    int first,second,third,fouth;
    char dot;
    while(cin>>first>>dot>>second>>dot>>third>>dot>>fouth)
    {
        if (first>=0&&first<=255&&second>=0&&second<=255&&third>=0&&third<=255&&fouth>=0&&fouth<=255)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
