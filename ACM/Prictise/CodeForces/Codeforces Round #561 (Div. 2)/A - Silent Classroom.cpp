#include<bits/stdc++.h>
using namespace std;

int tab[105], i, j, t, n,sum, suml;
string s;
char a[105];
void make_table()
{
	tab[1] = tab[2] = 0;
	j = 1;t = 1;
	for(i = 3;i <= 100;i++)
	{
		if(t > 2)
		{
			t = 1;
			j++;
		}
			
		tab[i] = tab[i-1] + j;
		t++;
	}
}

int main()
{
	make_table();
	
	cin >> n;
	for(i = 1;i <= n; i++)
	{
		cin >> s;
		a[i] = s[0];
	}
	
	for(i = 1;i <= n; i++)
	{
		if(a[i] == '0')
			continue;
		suml = 1;	
		
		for(j = i+1;j <= n; j++)
		{
			if(a[i] == a[j])
			{
				suml++;
				a[j] = '0';
			}	
		}
//		cout << suml << endl;
		sum += tab[suml];
	}
	cout << sum << endl;
}












