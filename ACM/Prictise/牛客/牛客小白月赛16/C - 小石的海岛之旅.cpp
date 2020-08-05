#include <iostream>
using namespace std;

int n,m,i,j,sum;
long long h[1005],a[1005];
bool ok = 0;

int main()
{
	scanf("%d %d",&n, &m);
	for(i = 1;i <= n; i++) scanf("%lld", &h[i]);
	for(i = 1;i <= m; i++) scanf("%lld", &a[i]);
	
	for(i = 1;i <= m; i++)
	{
		sum = 0;ok = 0;
		for(j = 1;j <= n; j++)
		{
			if(h[j] > a[i] && !ok){ok = 1;sum++;}
			if(h[j] <= a[i] && ok){ok = 0;}
		}
		cout << sum << endl;
	}
}