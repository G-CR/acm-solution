#include <bits/stdc++.h>
using namespace std;

long long n,ans,num_1,num0;
long long a[100005];

int main()
{
	scanf("%lld", &n);
	for(int i = 1;i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(abs(a[i]-1) < abs(a[i]+1))
		{
			ans += abs(a[i]-1);
		}
		else if(abs(a[i]-1) > abs(a[i]+1))
		{
			num_1++;
			ans += abs(a[i]+1);
		}
		else num0++;
	}
	ans += num0;
	if(num_1%2 && !num0) ans += 2;
	printf("%lld\n", ans);
}