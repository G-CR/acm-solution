#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+7;
int n;
map <char, int> mp1;
map <int, char> mp2;
vector <int> a;
void init() {
	mp1['B'] = 0; mp1['W'] = 1; mp1['R'] = 2;
	mp2[0] = 'B'; mp2[1] = 'W'; mp2[2] = 'R';
}

const int mod = 3;
ll fac[N];

ll qpow(ll x, ll n) {
	ll res = 1;
	for(; n; n >>= 1, x = x*x%mod)
		if(n & 1) res = res * res * x % mod;
	return res;
}

ll inv(ll a) {
	return qpow(a, mod-2) % mod;
}

void solve() {
	fac[0] = 1;
	for(int i = 1; i < N; i++) {
		fac[i] = (fac[i-1] * i) % mod;
	}
}

ll comb(ll n, ll k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n] * inv(fac[k])%mod * inv(fac[n-k]) % mod);
}

ll lucas(ll n, ll k) {
	if(n == 0) return 1 % mod;
	return lucas(n/mod, k/mod) * comb(n%mod, k%mod) % mod;
}


int main() {
	init();
	solve();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		char c; scanf(" %c", &c);
		a.push_back(mp1[c]);
	}
	
	int flag = n % 2 ? 1 : -1;
	ll ans = 0;
	for(int i = 0; i < a.size(); i++) {
		ans = (ans + lucas(n-1, i)*a[i]) % mod;
	}
	ans *= flag;
	if(ans < 0) {
		int num = -1 * ans / mod;
		ans += (num+1) * mod;
	}
	ans %= mod;
	printf("%c\n", mp2[ans]);
}