#include<iostream>
using namespace std;

char vowel[] = {'a','e','i','o','u','n'};
string s;

bool isVowel(char c)
{
	for(int i = 0;i < 6; ++i)
	{
		if(c == vowel[i])
			return true;
	}
	
	return false;
}

int main()
{
	cin >> s;
	int flag;
	for(int i = 0;i < s.length() - 1; ++i)
	{
		flag = 1;
		if(!isVowel(s[i]))
		{
			if(s[i+1] == 'n' || !isVowel(s[i+1]))
			{
				flag = 0;
				break;
			}
				
		}
	}
	
	if(!isVowel(s[s.length()-1]))
		flag = 0;
	
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
