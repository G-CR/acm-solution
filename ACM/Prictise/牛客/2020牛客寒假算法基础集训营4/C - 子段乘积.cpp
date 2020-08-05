#include <bits/stdc++.h>
using namespace std;
const int N = 200005, mod = 998244353;

int n, size;
long long ans, now, tree[N*4];

void build(int k,int l, int r) {
	if(l == r) {
		scanf("%lld", &tree[k]);
		tree[k] %= mod;
		return;
	}
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	tree[k] = (tree[2*k] * tree[2*k+1]) % mod;
}

void ask_interval(int la, int ra, int k, int l, int r) {
	if(la <= l && r <= ra) {
		now = (now*tree[k])%mod;
		return;
	}
	int mid = (l + r) / 2;
	if(la <= mid) ask_interval(la, ra, 2*k, l, mid);
	if(ra > mid) ask_interval(la, ra, 2*k+1, mid+1, r);
}

int main() {
	scanf("%d %d", &n, &size);
	build(1,1,n);
	for(int i = 1;i <= n; i++) {
		if(i+size-1 > n) break;
		now = 1;
		ask_interval(i, i+size-1, 1, 1, n);
		ans = max(ans, now);
	}
	printf("%lld\n", ans);
}