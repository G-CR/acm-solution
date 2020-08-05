#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,i;
int a[105];

int main() 
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		for(i = 1;i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		
		for(i = 1;i <= n-1; i++)
		{
			if(a[i] >= a[i+1])
			{
				int p = a[i] - (a[i+1]-k);
//				a[i] -= p;
				if(a[i] >= p)
					m += p;
				else m += a[i];
			}
			else
			{
				if(a[i] + m + k < a[i+1])
				{
					puts("NO");
					break;
				}
				else 
				{
					if(a[i+1] - a[i] <= k)
					{
						int p = k - (a[i+1]-a[i]);
						if(a[i] >= p) m += p;
						else m += a[i];
						continue;
					} 
					
					m -= a[i+1] - (a[i]+k);
				}
			}
		}
		if(i == n) puts("YES");
	}
}