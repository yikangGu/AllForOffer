#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		bool isMatch(string s, string p) 
		{
			const char *ss = s.c_str();
			const char *pp = p.c_str();
			if(ss == NULL || pp == NULL) return false;
			
			return matchResult(ss,pp);
		}
		bool matchResult(const char* ss,const char* pp)
		{
			if(*ss == '\0' && *pp == '\0') return true;
			if(*ss != '\0' && *pp == '\0') return false;

			if(*(pp + 1) == '*')
			{
				if((*ss == *pp) || (*pp == '.' && *ss != '\0'))
					return matchResult((ss + 1),pp) || matchResult(ss,(pp + 2));
				else
					return matchResult(ss,(pp + 2));

			}
			if((*ss == *pp) || (*pp == '.' && *ss != '\0'))
				return matchResult((ss + 1),(pp + 1));

			return false;
    
		}
};

int main()
{
	
	while(true)
	{
		string s;
		string p;
		bool result = 0;

		cout << "s=";
		getline(cin,s);
		cout << "p=";
		getline(cin,p);
		
		Solution solve;
		result = solve.isMatch(s,p);

		cout << result << endl;
	}

	return 0;
}