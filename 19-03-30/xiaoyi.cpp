#include<iostream>
using namespace std;
 
int divisor(int a, int b)
{
    if(b == 0)
        return a;
    else
        return divisor(b,a%b);
}
 
int main()
{
    int nums;
    int ability;
    int defens[100000];
    while(cin>>nums>>ability)
    {
        for(int i = 0; i < nums; i++)
        {
            cin >> defens[i];
        }
        for(int i = 0; i < nums; i++)
        {
            if(ability > defens[i])
            {
                ability += defens[i];
            }
            else
            {
                ability += divisor(ability,defens[i]);
            }
        }
        cout << ability << endl;
    }
    return 0;
}