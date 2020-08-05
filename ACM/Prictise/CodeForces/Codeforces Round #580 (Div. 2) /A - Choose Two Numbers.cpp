#include <bits/stdc++.h>
using namespace std;

int n,m,t,ans1,ans2;
int a[102],b[102];

bool inA(int t)
{
	for(int i = 1;i <= n; i++) if(t == a[i]) 
		return 1;
	return 0;
}

bool inB(int t)
{
	for(int i = 1;i <= m; i++) if(t == b[i]) 
		return 1;
	return 0;
}

int main() 
{
	bool ok = 0;
	
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1;i <= m; i++) scanf("%d", &b[i]);
	
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= m; j++)
		{
			t = a[i]+b[j];
			if(!inA(t) && !inB(t))
			{
				ok = 1;
				ans1 = a[i], ans2 = b[j];
				break;
			}
		}
		if(ok) break;
	}
	printf("%d %d\n", ans1, ans2);
}