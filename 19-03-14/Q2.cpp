#include <iostream>
#include <string>
#include <vector>

std::string longestPalindrome(std::string s){
    int length = s.size();
	int maxlength = 0;
	int start;
	std::vector<std::vector<bool>> P(length, std::vector<bool>(length, false));
	for(int i = 0; i < length; i++){
		P[i][i] = true;
		if(i < length-1 && s[i] == s[i+1])
		{
			P[i][i+1] = true;
			start=i;
			maxlength=2;
		}
	}
	for(int len = 3; len < length; len++)
		for(int i = 0; i <= length-len; i++)
		{
			int j = i + len - 1;
			if(P[i+1][j-1] && s[i] == s[j])
			{
				P[i][j] = true;
				maxlength = len;
				start = i;
			}
		}
	if(maxlength >= 2)
		return s.substr(start, maxlength);
    else
    	return NULL;
}

int main(){
    std::string testCase;    
    getline(std::cin, testCase);
    std::cout<<longestPalindrome(testCase)<<std::endl;
    return 0;
}

//testCase 1 pass!
//输入："babad"
//输出："aba"


//testCase 2 pass!
//输入："cbbd"
//输出："bb"
