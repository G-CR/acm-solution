#include <iostream>
#include <algorithm>
using namespace std;

int Map[100][100],i,j,n,sum,k;
int ans[100000];

void dfs(int x,int y)
{
	if(x > n || y > n) return;
	if(x == n && y == n){sum += Map[x][y]; ans[++k] = sum; return;}
	else sum += Map[x][y];
	dfs(x+1,y); sum -= Map[x+1][y];
	dfs(x,y+1); sum -= Map[x][y+1];
	return;
}

int main()
{
	cin >> n;
	for(i = 1;i <= n; i++)
		for(j = 1;j <= n; j++)
			cin >> Map[i][j];
	 dfs(1,1);
	sum = 0;
	sort(ans+1,ans+1+k);
	for(i = 1;i <= k-1; i++) if(ans[i] == ans[i+1]) ans[i] = -1;
	for(i = 1;i <= k; i++) if(ans[i] >= 0) sum++;
	cout << sum << endl;
}