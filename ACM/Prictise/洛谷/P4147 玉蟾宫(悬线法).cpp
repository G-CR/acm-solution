#include <iostream>
#include <cstring>
using namespace std;
const int n = 1005;

int N,M,i,j,ans;
char s[n][n];
int up[n][n],Left[n][n],Right[n][n];


int main()
{
	scanf("%d %d", &N, &M);
	for(i = 1;i <= N; i++)
		for(j = 1;j <= M; j++)
		{
			scanf(" %c", &s[i][j]);
			Left[i][j] = Right[i][j] = j;
			up[i][j] = 1;
		}
		
	for(i = 1;i <= N; i++)
	{
		for(j = 1;j <= M; j++)
		{
			if(s[i][j] == 'F' && s[i][j-1] == 'F')
				Left[i][j] = Left[i][j-1];
		}
		for(j = M;j >= 1; j--)
		{
			if(s[i][j] == 'F' && s[i][j+1] == 'F')
				Right[i][j] = Right[i][j+1];
		}
	}
	
	for(i = 1;i <= N; i++)
	{
		for(j = 1;j <= M; j++)
		{
			if(i > 1 && s[i][j] == 'F' && s[i-1][j] == 'F')
			{
				up[i][j] = up[i-1][j] + 1;
				Left[i][j] = max(Left[i][j],Left[i-1][j]);
				Right[i][j] = min(Right[i][j],Right[i-1][j]);
			}
			ans = max(ans,(Right[i][j]-Left[i][j]+1)*up[i][j]);
		}
	}
	cout << 3 * ans << endl;
}