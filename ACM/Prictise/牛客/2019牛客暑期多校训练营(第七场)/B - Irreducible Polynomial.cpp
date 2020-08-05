#include <bits/stdc++.h>
using namespace std;

int T,n;
long long a[25];

int main() 
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1;i <= n+1; i++)
			scanf("%lld", &a[i]);
			
		if(n > 2) {puts("No"); continue;}
		if(n < 2) {puts("Yes"); continue;}
		
		long long der = a[2]*a[2] - 4*a[1]*a[3];
		if(der >= 0) puts("No");
		else puts("Yes");
	}
}