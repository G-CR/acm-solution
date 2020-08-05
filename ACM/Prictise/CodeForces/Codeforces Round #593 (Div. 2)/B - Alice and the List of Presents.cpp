#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

long long poww(long long  a,long long b)
{
	long long ans = 1, base = a;
	while(b)
	{
		if(b&1)
			ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans%mod;
}

int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long ans = poww((poww(2,m)-1), n)%mod;
	cout << ans << endl;
}