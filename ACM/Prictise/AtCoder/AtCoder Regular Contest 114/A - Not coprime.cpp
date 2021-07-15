#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;

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

int n;
ll a[N];

set <ll> tmp;
vector <ll> d;

bool check(ll k) {
	for(int i = 1; i <= n; i++) {
		if(__gcd(k, a[i]) == 1) return 0;
	}
	return 1;
}

ll dfs(int p, ll now) {
	if(p == d.size()) {
		if(check(now)) {
			return now;
		}
		return 1e18;
	}
	
	ll res = min(dfs(p+1, now), dfs(p+1, now*d[p]));
	return res;
}

int main() {
	getprime();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for(int i = 1; i <= n; i++) {
		int now = a[i];
		for(int j = 0; j < pn; j++) {
			if(now % prime[j] == 0) {
				tmp.insert(prime[j]);
				while(now % prime[j] == 0) {
					now /= prime[j];
				}
			}
		}
	}
	
	for(ll i: tmp) d.push_back(i);
	printf("%lld", dfs(0, 1ll));
}