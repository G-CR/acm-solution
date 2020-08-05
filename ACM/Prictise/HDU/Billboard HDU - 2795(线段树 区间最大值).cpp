#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

int tree[maxn<<2];
int h, w, n, x;

void build(int l, int r, int k) {
	if(l == r) {
		tree[k] = w;
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, k<<1);
	build(mid+1, r, k<<1|1);
	
	tree[k] = max(tree[k<<1], tree[k<<1|1]);
}

int qu(int val, int l, int r, int k) {
	if(l == r) {
		tree[k] -= val;
		return l;
	}
	int ans = -1, mid = (l+r)>>1;
	if(tree[k<<1] >= val) ans = qu(val, l, mid, k<<1);
	else ans = qu(val, mid+1, r, k<<1|1);
	
	tree[k] = max(tree[k<<1], tree[k<<1|1]);
	return ans;
}

int main() {
	while(~scanf("%d %d %d", &h, &w, &n)) {
		if(h > n) h = n;
		build(1, h, 1);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(x > tree[1]) puts("-1");
			else {
				printf("%d\n", qu(x, 1, h, 1));
			}
		}
	}
}