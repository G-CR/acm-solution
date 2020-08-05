#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;

int n, m, gra[maxn<<2], a, b;
char ch;

void build(int l, int r, int k) {
	if(l == r) {
		scanf("%d", &gra[k]);
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, k<<1);
	build(mid+1, r, k<<1|1);
	
	gra[k] = max(gra[k<<1], gra[k<<1|1]);
}

int qu(int L, int R, int l, int r, int k) {
	if(L <= l && r <= R) {
		return gra[k];
	}
	
	int ans = -1, mid = (l+r)>>1;
	if(L <= mid) ans = max(ans, qu(L, R, l, mid, k<<1));
	if(R > mid) ans = max(ans, qu(L, R, mid+1, r, k<<1|1));
	
	return ans;
}

void up(int val, int L, int R, int l, int r, int k) {
	if(l == r) {
		gra[k] = val;
		return;
	}
	
	int mid = (l+r)>>1;
	if(L <= mid) up(val, L, R, l, mid, k<<1);
	if(R > mid) up(val, L, R, mid+1, r, k<<1|1);
	
	gra[k] = max(gra[k<<1], gra[k<<1|1]);
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		build(1, n, 1);
		while(m--) {
			scanf(" %c %d %d", &ch, &a, &b);
			if(ch == 'Q') {
				printf("%d\n", qu(a, b, 1, n, 1));
			}
			else if(ch == 'U') {
				up(b, a, a, 1, n, 1);
			}
		}
	}
	
}