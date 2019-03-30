#include <iostream>
#include <vector>

using namespace std;


int maxCommon(int m, int n){
    if (m < n) {// 保证m>n,若m<n,则进行数据交换
			int temp = m;
			m = n;
			n = temp;
		}
    if (m % n == 0) // 若余数为0,返回最大公约数
        return n;
    else // 否则,进行递归,把n赋给m,把余数赋给n
        return maxCommon(n, m % n);
}

int maxCnt(int n, int a2, vector<int>b){
    int a = a2;
    for(int i=0; i<n; i++){
        if (a >= b[i])
            a += b[i];
        else
            a += maxCommon(b[i], a);
    }
    return a;
}


int main(){
    
    int n,a,b;
    vector<int> bn;
    cin >> n >> a;
    while(cin>>b){
        bn.push_back(b);
    }
    
    cout << maxCnt(n, a, bn) << endl;
    
    return 0;
}
