#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, k;

long long fa[100005], num[100005], zo;
bool vis[100005];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int find(int x) {
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return x;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		fa[i] = i; num[i] = 1; vis[i] = 0;
	}
	
	int u, v;
	for(int i = 1;i < n; i++) {
		scanf("%d %d %lld", &u, &v, &zo);
		if(zo == 1) continue;
		fa[find(u)] = find(v);
	}
	
	for(int i = 1;i <= n; i++) {
		int f = find(i);
		if(f == i) continue;
		num[f]++;
	}
	
	long long sum = 0;
	for(int i = 1;i <= n; i++) {
		int f = find(i);
		if(vis[f]) continue;
		vis[f] = 1;
		sum = (sum + (qpow(num[f], k)))%mod;
	}
	
	printf("%lld\n", (qpow(n,k)-sum+mod)%mod);
}