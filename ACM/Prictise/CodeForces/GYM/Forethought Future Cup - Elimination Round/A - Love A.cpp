#include<iostream>
using namespace std;

string s;
int suma;

int main()
{
	cin >> s;
	for(int i = 0;i <= s.length()-1; ++i)
		if(s[i] == 'a')
			suma++;
	if(2*suma <= s.length())
		cout << 2*suma-1;
	else cout << s.length();
}
