#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int> &height)
{
    int s = 0;
    for (size_t i = 0; i < height.size(); i++)
        for (size_t j = i + 1; j < height.size(); j++)
            s = max((int)(min(height[i] , height[j])*(j-i)), s);
    return s;
}

int main(int argc, char const *argv[])
{
    vector<int> data = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(data);
    cout << " max area: " << result << endl;
    return 0;
}
