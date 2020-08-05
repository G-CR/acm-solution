#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;

ll n,m,ans;

ll poww(ll a,ll b)
{
	ll ans = 1,base = a;
	while(b)
	{
		if(b&1)
			ans = ans * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
}


int main() 
{
	while(~scanf("%lld %lld", &n, &m))
	{
		ll tot = poww(m, n)%mod;
		ans = (tot - m*poww(m-1,n-1)%mod + mod) % mod;
		printf("%lld\n", ans);
	}
	
}