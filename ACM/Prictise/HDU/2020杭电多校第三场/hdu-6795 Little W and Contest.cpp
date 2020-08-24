#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int _, n, x, u, v, fa[100005];
struct node {
	long long one;
	long long two;
	long long tot;
} acm[100005];
long long fac[100005];
long long qpow(long long x, long long n) {
	long long res = 1;
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res;
}
long long inv(long long a) {
	return qpow(a, mod-2)%mod;
}
void solve() {
	fac[0] = 1;
	for(int i = 1;i <= 100005; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}
long long comb(long long n, long long k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod);
}
int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		long long num1 = 0, num2 = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) fa[i] = i;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			node t;
			if(x == 1) {
				t.one = 1; t.two = 0; 
				num1++;
			} 
			if(x == 2) {
				t.one = 0; t.two = 1;
				num2++;
			}
			t.tot = t.one + t.two;
			acm[i] = t;
		}
		
		long long ans = ((comb(num2, 2)*comb(num1, 1))%mod+comb(num2, 3))%mod;
		long long res = 0;
		printf("%lld\n", ans);
		for(int i = 0;i < n-1; i++) {
			scanf("%d %d", &u, &v);
			int x = find(u), y = find(v);
			if(x == y) continue;
			long long one1 = acm[x].one, one2 = acm[y].one, two1 = acm[x].two, two2 = acm[y].two;
			res = (res+ comb(two1, 1) * comb(two2, 1)%mod * comb(num2-two1-two2, 1))%mod;
			res = (res+ comb(two1, 1) * comb(two2, 1)%mod * comb(num1-one1-one2, 1))%mod;
			res = (res+ comb(two1, 1) * comb(one2, 1)%mod * comb(num2-two1-two2, 1))%mod;
			res = (res+ comb(one1, 1) * comb(two2, 1)%mod * comb(num2-two1-two2, 1))%mod;
			acm[y].one += acm[x].one;
			acm[y].two += acm[x].two;
			acm[y].tot = acm[y].one + acm[y].two;
			fa[x] = y;
			printf("%lld\n", (ans-res+mod)%mod);
		}
	}
}