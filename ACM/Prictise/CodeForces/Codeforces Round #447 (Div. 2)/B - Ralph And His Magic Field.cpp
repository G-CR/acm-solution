#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;

ll poww(ll a,ll b)
{
	a %= mod;
	ll ans = 1,base = a;
	while(b)
	{
		if(b&1)
			ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans;
}
ll n, m;
int k;

int main() {
	scanf("%lld %lld %d", &n, &m, &k);
	if(n%2!=m%2 && k==-1) puts("0");
	else {
		long long t1 = poww(2, n-1);
		long long t2 = poww(t1%mod, m-1);
		printf("%lld\n", (t2+mod)%mod);
	}
}