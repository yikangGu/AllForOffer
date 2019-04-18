#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int s = 0;
    for (size_t i = 0; i < prices.size(); i++)
        for (size_t j = i + 1; j < prices.size(); j++)
            s = max(prices[j] - prices[i], s);
    return s;
}

int main(int argc, char const *argv[])
{
    vector<int> set1 = {7,1,5,3,6,4};
    vector<int> set2 = {7,6,4,3,1};

    cout << " set1 max profit: " << maxProfit(set1) << endl;
    cout << " set2 max profit: " << maxProfit(set2) << endl;
    return 0;
}
