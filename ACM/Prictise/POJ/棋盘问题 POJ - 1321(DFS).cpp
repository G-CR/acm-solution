#include <iostream>
using namespace std;

int n,k,ans;
char a[10][10];
bool flag[10];

void dfs(int line)
{
	if(k == 0){ans++; return;}
	if(line == n+1) return;
	
	for(int i = line;i <= n; i++)
	{	
		for(int j = 1;j <= n; j++)
		{
			if(!flag[j] && a[i][j] == '#')
			{
				flag[j] = 1; k--; 
				//cout <<"i = " << i << " j = " << j << endl;
				dfs(i+1);
				flag[j] = 0; k++;
			}
		}	
	}
	return;
}

int main() 
{
	while(1)
	{
		ans = 0;
		memset(flag,0,sizeof(flag));
		scanf("%d %d",&n, &k); if(n == -1 && k == -1) return 0;
		for(int i = 1;i <= n; i++)
			for(int j = 1;j <= n; j++)
				scanf(" %c", &a[i][j]);
			
		dfs(1);
		
		cout << ans << endl;
	}
}