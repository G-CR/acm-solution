#include<bits/stdc++.h>
using namespace std;

int n,m,i,j;
int ma1[55][55],ma2[55][55];

int max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a < b)
		return a;
	else 
		return b;
}

int main()
{
	cin >> n >> m;
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m; j++)
			cin >> ma1[i][j];
			
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m; j++)
			cin >> ma2[i][j];
			
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m; j++)
		{
				if(max(ma1[i][j],ma2[i][j]) > max(ma1[i][j-1],ma2[i][j-1])  //Ïò×ó 
				 &&min(ma1[i][j],ma2[i][j]) > min(ma1[i][j-1],ma2[i][j-1])
				 &&max(ma1[i][j],ma2[i][j]) > max(ma1[i-1][j],ma2[i-1][j]) // ÏòÉÏ 
				 &&min(ma1[i][j],ma2[i][j]) > min(ma1[i-1][j],ma2[i-1][j]))
					continue; 
					
				else
				{
					cout << "Impossible" << endl;
					return 0;
				}
		}
	cout << "Possible" << endl;
}

