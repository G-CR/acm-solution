#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int S = 8;
	
inline ll mult_mod(ll a, ll b, ll c) {
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b) {
		if(b & 1) {
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}

inline ll pow_mod(ll a, ll n, ll mod) {
	ll ret = 1;
	ll tmp = a % mod;
	while(n) {
		if(n & 1) ret = mult_mod(ret, tmp, mod);
		tmp = mult_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}

inline bool check(ll a, ll n, ll x, ll t) {
	ll ret = pow_mod(a, x, n);
	ll last = ret;
	for(int i = 1; i <= t; i++) {
		ret = mult_mod(ret, ret, n);
		if(ret == 1 && last != 1 && last != n-1) return true;
		last = ret;
	}
	if(ret != 1) return true;
	else return false;
}

inline bool Miller_Rabin(ll n) {
	if(n < 2) return false;
	if(n == 2) return true;
	if((n & 1) == 0) return false;
	ll x = n - 1;
	ll t = 0;
	while((x & 1) == 0) {x >>= 1; t++;}
	
	for(int i = 0; i < S; i++) {
		ll a = rand() % (n-1) + 1;
		if(check(a, n, x, t))
			return false;
	}
	return true;
}

ll ans, factor[100];
int tol;

inline ll gcd(ll a, ll b) {
	ll t;
	while(b) {
		t = a;
		a = b;
		b = t%b;
	}
	if(a >= 0) return a;
	else return -a;
}

inline ll pollard_rho(ll x, ll c) {
	ll i = 1, k = 2;
	ll x0 = rand() % (x-1) + 1;
	ll y = x0;
	while(1) {
		i++;
		ll x0 = (mult_mod(x0, x0, x) + c) % x;
		ll d = gcd(y-x0, x);
		if(d != 1 && d != x) return d;
		if(y == x0) return x;
		if(i == k) {y = x0; k += k;}
	}
}

inline void findfac(ll n, int k) {
	if(n == 1 || n < ans) return;
	if(Miller_Rabin(n)) {
		ans = max(ans, n);
		return;
	}
	ll p = n;
	int c = k;
	while(p >= n) p = pollard_rho(p, c--);
	findfac(p, k);
	findfac(n/p, k);
}

int main() {
	srand(time(NULL));
	int _; scanf("%d", &_);
	while(_--) {
		ans = 0;
		ll n; scanf("%lld", &n);
		if(Miller_Rabin(n)) puts("Prime");
		else {
			tol = 0;
			findfac(n, 107);
			printf("%lld\n", ans);
		}
	}
}