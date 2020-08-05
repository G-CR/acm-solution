#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
struct node {
	int l, r;
	long long data;
}tree[400005];
int n, q, L, R, x;
long long ans;
 
void build(int l,int r, int k) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {
		scanf("%lld", &tree[k].data);
		return;
	}
	 
	int mid = (l + r) / 2;
	build(l, mid, 2*k);
	build(mid+1, r, 2*k+1);
	 
	tree[k].data = tree[2*k].data + tree[2*k+1].data;
}
 
 
void change_interval(int k) {
	if(tree[k].data == 0) return;
	if(tree[k].l == tree[k].r) {
		tree[k].data /= 2;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if(L <= mid) change_interval(2*k);
	if(R > mid) change_interval(2*k+1);
	 
	tree[k].data = tree[2*k].data + tree[2*k+1].data;
}
 
void ask(int k) {
	if(L <= tree[k].l && tree[k].r <= R) {
		ans += tree[k].data;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if(L <= mid) ask(2*k);
	if(R > mid) ask(2*k+1);
}
 
 
int main() {
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	while(q--) {
		ans = 0;
		scanf("%d %d %d", &x, &L, &R);
		if(x == 1) {
			change_interval(1);
		}
		 
		else {
			ask(1);
			printf("%lld\n", ans);
		}
	}
}