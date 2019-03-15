#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) 
		{
			int begin = 0;
			int subLen = 0;
			int maxSubLen = 0;

			int len = s.length();

			bool **dp = new bool *[len];
			for(int i = 0; i < len;i++) dp[i] = new bool[len];

			for(int i = 0; i < len;i++)
			{
				for(int j = 0; j < len;j++) dp[i][j] = false;
			}

			for(int i = 0; i < len;i++)
			{
				dp[i][i] = true;
				subLen = 1;
				if(subLen > maxSubLen)
				{
					begin = i;
					maxSubLen = subLen;
				}

				if((i < len - 1) && (s.at(i) == s.at(i+1)))
				{
					dp[i][i+1] = true;
					subLen = 2;
					if(subLen > maxSubLen)
					{
						begin = i;
						maxSubLen = subLen;
					}
				}
				for(int tmplen = 3; tmplen < len; tmplen++)
				{
					for(int i = 0; i < len - tmplen + 1;i++)
					{
						int j = i + tmplen - 1;
						if(dp[i+1][j-1]&&(s.at(i) == s.at(j)))
						{
							dp[i][j] = true;
							subLen = tmplen;
						}
						if(subLen > maxSubLen)
						{
							begin = i;
							maxSubLen = subLen;
						}
					}
				}
			}
			for(int i = 0; i < len;i++) delete[] dp[i];
			delete[]dp;

			return s.substr(begin,maxSubLen);
		}
	};

int main()
{
	while(true)
	{
		string s;
		string subS;
		getline(cin,s);

		Solution solve;
		subS = solve.longestPalindrome(s);

		cout << subS << endl;
	}

	return 0;
}