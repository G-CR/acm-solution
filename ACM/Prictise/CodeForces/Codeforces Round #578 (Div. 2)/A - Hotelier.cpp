#include <bits/stdc++.h>
using namespace std;

int n;
bool ok[10];
char x;
int main()
{
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		cin >> x;
		if(x >= '0' && x <= '9')
		{
			int a = x - '0';
			ok[a] = 0;
			continue;
		}
		else
		{
			if(x == 'L')
			{
				for(int j = 0; j <= 9; j++)
					if(ok[j] == 0) 
					{
						ok[j] = 1;
						break;
					}
			}
			else 
			{
				for(int j = 9; j >= 0; j--)
					if(ok[j] == 0)
					{
						ok[j] = 1;
						break;
					} 
			}
		}
	}
	for(int i = 0;i <= 9; i++) cout << ok[i];
}