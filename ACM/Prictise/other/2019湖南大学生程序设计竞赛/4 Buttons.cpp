#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll n,a,b,c,d,ans;

int main() {
	while(~scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d)) {
		ll ans1 = ( ( n*( (a+b+c+d) % mod ) ) %mod ) % mod;
		ll num = ( n*(n-1)/2 ) % mod;
		ll ans2 = ( (a*b)%mod + (b*c)%mod + (c*d)%mod + (d*a)%mod ) %mod;
		ans = (1 + ans1 + (num * ans2) % mod ) % mod;
		printf("%lld\n", ans);
	}
}