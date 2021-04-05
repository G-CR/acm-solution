#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m[20], a[20];

void exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x = 1; y = 0;
		return;
	}
	exgcd(b, a%b, y, x);
	y -= a/b*x;
}

ll crt() {
	ll M = 1;
	for(int i = 1; i <= n; i++) M *= m[i];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ll x, y, Mi;
		Mi = M / m[i];
		exgcd(Mi, m[i], x, y);
		ans = (ans + a[i]*Mi*x) % M;
	}
	
	if(ans < 0) ans += M;
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &m[i], &a[i]);
	}
	printf("%lld\n", crt());
}