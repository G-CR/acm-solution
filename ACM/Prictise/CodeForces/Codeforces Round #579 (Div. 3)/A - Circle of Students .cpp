#include <bits/stdc++.h>
using namespace std;

int q,n,sta;
int a[405];

int main() 
{
	cin >> q;
	while (q--)
	{
		scanf("%d", &n);
		bool ok1 = 1, ok2 = 1;
		
		for(int i = 1;i <= n; i++)
		{
			scanf("%d", &a[i]);
			if(a[i] == 1) sta = i;
		}
		for(int i = n+1;i <= 2*n; i++) a[i] = a[i-n];
		
		for(int i = sta+2;i <= sta+n-1; i++) //递减
			if(a[i] > a[i-1]) ok1 = 0;
		
		for(int i = sta+2;i <= sta+n-1; i++) //递增
			if(a[i] < a[i-1]) ok2 = 0;
		
		if(ok1 || ok2) puts("YES");
		else puts("NO");
	}
}