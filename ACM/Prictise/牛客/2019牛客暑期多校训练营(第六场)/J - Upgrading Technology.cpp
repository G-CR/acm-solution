#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll t,m,n,i,j,x,ans,q=1;
ll a[1005][1005],tot[1005],Min[1005][1005];

int main() 
{
	scanf("%lld", &t);
	while(t--)
	{
		memset(Min,0,sizeof(Min));
		memset(a,0,sizeof(a));
		memset(tot,0,sizeof(tot));
		
		scanf("%lld %lld", &n, &m);
		for(i = 1;i <= n; i++)
		{
			for(j = 1;j <= m; j++)
			{
				scanf("%lld", &x);
				a[i][j] = a[i][j-1]+x;
			}
			
			Min[i][m] = a[i][m];
			for(int j = m - 1; j >= 0; --j) 
				Min[i][j] = min(Min[i][j + 1], a[i][j]);
		}
						
		for(i = 1;i <= m; i++)
		{
			scanf("%lld", &x);
			x = -x;
			tot[i] = tot[i-1]+x;
		}
					
		
//		for(i = 1;i <= n; i++)
//		{
//			for(j = 1;j <= m; j++)
//				cout << Min[i][j] << " ";
//			cout << endl;
//		}
		ans = 0;
		for(int j = 0; j <= m; ++j) 
		{
			ll tmp = tot[j];
			ll ma = -inf;
			int num = 0; 
			for(int i = 1; i <= n; ++i)
			{
				tmp += a[i][j]; 
				if(Min[i][j] - a[i][j] < 0) 
				{
					tmp += Min[i][j] - a[i][j];
					ma = max(ma, Min[i][j] - a[i][j]);
					++num;
				}
			}
			if(num == n) tmp -= ma;
			ans = min(ans, tmp); //加上tot再减去最小，不会往右扩展
		}
		
		printf("Case #%lld: %lld\n", q++, -ans);
	}
}

