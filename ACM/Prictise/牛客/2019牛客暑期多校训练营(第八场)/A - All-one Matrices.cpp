#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int up[N][N],sum[N][N],L[N],R[N];
int m,n,i,j,ans;
char mp[N][N];
stack <int> sst;

int main() 
{
	scanf("%d %d",&n, &m);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= m; j++)
		{
			scanf(" %c", &mp[i][j]);
			if(mp[i][j] == '1')
				up[i][j] = up[i-1][j]+1;
			sum[i][j] = sum[i][j-1]+(mp[i][j]-'0');
		}
	}
	ans = 0;
	for(i = n;i >= 1; i--)
	{
		while(!sst.empty()) sst.pop();
		sst.push(m+1);
		for(j = m;j >= 1; j--)
		{
			while(!sst.empty() && up[i][j] <= up[i][sst.top()])
				sst.pop();
			if(sst.empty()) R[j] = -1;
			else R[j] = sst.top()-1;
			sst.push(j);
		}
		
		while(!sst.empty()) sst.pop();
		sst.push(0);
		for(j = 1;j <= m; j++)
		{
			while(!sst.empty() && up[i][j] <= up[i][sst.top()])
				sst.pop();
			if(sst.empty()) L[j] = -1;
			else L[j] = sst.top()+1;
			sst.push(j);
		}
		
		while(!sst.empty()) sst.pop();
		
		for(j = 1;j <= m; j++)
		{
			if(up[i][j] == 0)
			{
				while(!sst.empty()) 
					sst.pop();
				continue;
			}
			
			while(!sst.empty() && up[i][j] < up[i][sst.top()])
				sst.pop();
			if(sst.empty() || up[i][j] != up[i][sst.top()])
			{
				int left = L[j];
				int right = R[j];
				if(sum[i+1][right] - sum[i+1][left-1] != right-left+1)
				{
					ans++;
					sst.push(j);
				}
			}
		}
	}
	printf("%d\n",ans);		
}