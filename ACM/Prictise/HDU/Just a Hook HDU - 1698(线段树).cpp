#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int T,x,y,z,lazy[N*4];
struct Tree{
	int l, r, f, val;
} tree[N*4];

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r; tree[k].f = 0;
	if(r == l) {
		tree[k].val = 1;
		return;
	}
	
	int mid = (l+r)/2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	
	tree[k].val = tree[2*k].val + tree[2*k+1].val;
}

void down(int k)
{	
	if(tree[k].l == tree[k].r) return;
	
	if(tree[k].f) {
		tree[2*k].val = (tree[2*k].r - tree[2*k].l + 1) * tree[k].f;
		tree[2*k].f = tree[k].f;
		tree[2*k+1].val = (tree[2*k+1].r - tree[2*k+1].l + 1) * tree[k].f;
		tree[2*k+1].f = tree[k].f;
		tree[k].f = 0;
	}
}

void change_interval(int k) {
	if(x <= tree[k].l  && tree[k].r <= y) {
		tree[k].val = (tree[k].r - tree[k].l + 1) * z;
		tree[k].f = z;
		return;
	}
	down(k);
	int mid = (tree[k].l + tree[k].r)/2;
	if(x <= mid) change_interval(2*k);
	if(y > mid) change_interval(2*k+1);
	
	tree[k].val = tree[2*k].val + tree[2*k+1].val;
}

int main() {
	scanf("%d", &T);
	int n,q;
	for(int p = 1;p <= T; p++) {
		scanf("%d %d", &n, &q);
		build(1,1,n);
		for(int i = 1;i <= q; i++) {
			scanf("%d %d %d", &x, &y, &z);
			change_interval(1);
		}
		printf("Case %d: The total value of the hook is %d.\n",p ,tree[1].val);
	}
}