#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

const int N = 1e5;
int isprime[N+10], prime[N+10];
int pn = 0;
void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

ll dfs(int d, int p) {
	if(d < p) return 0;
	return dfs(d/p, p) + d/p;
}

int main() {
	getprime();
	int _; scanf("%d", &_); while(_--) {
		ll n; scanf("%lld", &n);
		
		vector <ll> g;
		for(int i = 0; prime[i] <= n; i++) {
			g.push_back(dfs(n, prime[i]));
		}
		
		ll ans = 1;
		for(ll i: g) {
			ans = (ans * (i + 1)) % mod;
		}
		
		printf("%lld\n", ans);
	}
}