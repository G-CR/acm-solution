#include <bits/stdc++.h>
using namespace std;

int n;
int a[150005];

int main() 
{
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	for(int i = 1;i <= n; i++)
	{
		if(a[i] < a[i-1]) {a[i]++; continue;}
		if(a[i] == a[i-1]){ans++; a[i]++; continue;}
		if(a[i] > a[i-1])
		{
			if(a[i]-1 > a[i-1]) {ans++;a[i]--; continue;}
			if(a[i] - 1 == a[i-1]) {ans++;continue;}
		}
	}
	printf("%d\n",ans);
}