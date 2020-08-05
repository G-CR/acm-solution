#include <bits/stdc++.h>
using namespace std;

int m,h0 = 1,r0 = 1,h,r;
int a[1100][1100];

void sst(int n)
{
	h = 2*h0; r = 2*r0;
	for(int i = 1;i <= h0;i++)
		for(int j = r0+1;j <= r; j++)
			a[i][j] = a[i][j-r0];
			
	for(int i = h0+1;i <= n; i++)
		for(int j = 1;j <= r0; j++)
			a[i][j] = a[i-h0][j];
	
	for(int i = h0+1;i <= n; i++)
		for(int j = r0+1;j <= n; j++)
			a[i][j] = -a[i-h0][j-r0];
			
	h0 *= 2; r0 *= 2;
}

int main() 
{
	scanf("%d", &m);
	a[1][1] = 1;
	for(int i = 2;i <= m;i *= 2) sst(i);
	
	for(int i = 1;i <= m; i++)
	{
		for(int j = 1;j <= m; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
		
}