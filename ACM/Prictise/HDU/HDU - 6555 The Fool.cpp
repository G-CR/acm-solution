#include <iostream>
#include <cmath>
using namespace std;

int T;
long long i,n,sum,ans,r;

int main()
{
	scanf("%d", &T);
	int t = T;
	while(T--)
	{
		scanf("%lld", &n);	
		ans = 0;
		for(i = 1,r = 0;i <= n; i = r+1)
		{
			r = n/(n/i);
			ans += (r-i+1)*(n/i);
		}
		printf("Case %d: ",t-T);
		if(ans % 2) printf("odd\n");
		else printf("even\n");
	}
}