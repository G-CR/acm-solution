#include <iostream>
#include <cstring>
using namespace std;

string s;
long long i,j,numw,sum;

int main()
{
	cin >> s;
	int pre[s.length()];
	for(i = 0;i < s.length(); i++)
	{
		if(i && s[i] == 'v' && s[i-1] == 'v') numw++;
		else if(s[i] == 'o') pre[i] = numw;
	}
	
//	cout << "numw = " << numw << endl;
	
	for(i = 0;i < s.length()-1; i++)
	{
		if(s[i] == 'o')
		{
			sum += pre[i]*(numw-pre[i]);
		}
	}
	cout << sum << endl;
}