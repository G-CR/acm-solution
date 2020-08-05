#include <bits/stdc++.h>
using namespace std;

int q,n,x;
int a[10005],now1[10005],now2[10005];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	cin >> q;
	while(q--)
	{
		scanf("%d", &n);
		int t = n*4,j = 0;
		bool ok = 1;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= t; i++)
		{
			scanf("%d", &x);
			a[x]++;
			if(a[x] == 2)
			{
				now1[++j] = x;
				now2[j] = x;
				a[x] = 0;
			}
		}
		
		if(j < n*2) { puts("NO"); continue;}
		sort(now1+1,now1+1+j);
		sort(now2+1,now2+1+j,cmp);
		int tt = now1[1]*now2[1];
		for(int i = 1;i <= j/2; i++)
		{
			if(tt != now1[i]*now2[i])
			{
				ok = 0;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
		
	}
}