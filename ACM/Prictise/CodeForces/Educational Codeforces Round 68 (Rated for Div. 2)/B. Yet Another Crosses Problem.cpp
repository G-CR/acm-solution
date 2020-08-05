#include <iostream>
#include <cmath>
using namespace std;

int i,j,q,m,n,ans,cnt1[50005],cnt2[50005];
string a[50005];

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		ans = 2147483647;
		for(i = 0;i < n; i++) cnt1[i]=0;
		for(i = 0;i < m; i++) cnt2[i]=0;
		
		cin >> n >> m;
		for(i = 0;i < n; i++) cin >> a[i];
		
		for(i = 0;i < n; i++)
			for(j = 0; j < m; j++) 
				if(a[i][j] == '.') cnt1[i]++,cnt2[j]++;
		
		for(i = 0;i < n; i++)
			for(j = 0; j < m; j++)
				ans = min(ans,cnt1[i]+cnt2[j]-(a[i][j]=='.'));
			
		cout << ans << endl;
	}
}