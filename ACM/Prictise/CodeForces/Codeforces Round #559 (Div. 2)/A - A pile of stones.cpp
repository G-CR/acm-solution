#include<iostream>
using namespace std;

char s[55];
int n,i,t;

int main()
{
	cin >> n;
	for(i = 1;i <= n; ++i)
		cin >> s[i];
	for(i = 1;i <=n; ++i)
	{
		if(s[i] == '+')
			t++;
		if(s[i] == '-')
			t--;
		if(t < 0)
			t = 0;
	}
	
	cout << t << endl;
}
