#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+5;
int a[N],vis[N];
ll n,ans;

int main() 
{
	scanf("%lld", &n);
	for(ll i = 1;i <= n; i++)
	{
		scanf("%d", &a[i]);
		ll t = i - vis[a[i]];
		ans += t * (n-i+1);
		vis[a[i]] = i;
	}
	printf("%lld\n", ans);
}