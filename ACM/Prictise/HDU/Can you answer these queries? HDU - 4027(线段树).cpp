#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

struct Tree {
	int l, r;
	long long m, val;
} tree[N*4];

int n, m, a, b, c;
long long ans;

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {
		scanf("%lld", &tree[k].val);
		tree[k].m = tree[k].val;
		return;
	} 
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	tree[k].val = tree[2*k].val + tree[2*k+1].val;
	tree[k].m = max(tree[2*k].m, tree[2*k+1].m);
}

void change_point(int k) {
	if(b <= tree[k].l && tree[k].r <= c) {
		if(tree[k].m <= 1) return;
	}
	
	if(tree[k].l == tree[k].r) {
		tree[k].val = floor(sqrt(tree[k].val));
		tree[k].m = tree[k].val;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(b <= mid) change_point(2*k);
	if(c > mid) change_point(2*k+1);
	
	tree[k].val = tree[2*k].val + tree[2*k+1].val;
	tree[k].m = max(tree[2*k].m, tree[2*k+1].m);
}


void ask(int k) {
	if(b <= tree[k].l && tree[k].r <= c) {
		ans += tree[k].val;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(b <= mid) ask(2*k);
	if(c > mid) ask(2*k+1);
}

int main() {
	int cnt = 1;
	while(~scanf("%d", &n)) {
		printf("Case #%d:\n", cnt++);
		build(1, 1, n);
		scanf("%d", &m);
		for(int i = 1;i <= m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if(b > c) swap(b, c);
			if(a == 0) {
				change_point(1);
			}
			else {
				ans = 0;
				ask(1);
				printf("%lld\n", ans);
			}
		}
		puts("");
	}
}