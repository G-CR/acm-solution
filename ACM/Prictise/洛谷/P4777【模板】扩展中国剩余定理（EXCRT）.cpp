#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

long long mod[100005], x[100005];
int n;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) {
		x = 1; y = 0;
		return a;
	}
	ll gcd = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return gcd;
}

long long excrt() {
	ll lcm = mod[1], last_x = x[1];
	for(int i = 2; i <= n; i++) {
		ll lcm_a = (x[i]-last_x+mod[i])%mod[i];
		ll x, y, k = lcm;
		ll gcd = exgcd(lcm, mod[i], x, y);
		if(lcm_a % gcd) return -1;
		x = (x * lcm_a / gcd % (mod[i]/gcd) + (mod[i]/gcd)) % (mod[i]/gcd);
		lcm = lcm * mod[i] / gcd;
		last_x = (last_x + k * x % lcm)%lcm;
	}
	return (long long)(last_x%lcm+lcm)%lcm;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld", &mod[i], &x[i]);
	}
	
	printf("%lld\n", excrt());
}