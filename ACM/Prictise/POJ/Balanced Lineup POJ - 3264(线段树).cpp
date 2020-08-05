#include<iostream>
#include<cstdio>
using namespace std;
const int N = 50005;
struct Tree{
	int l, r, Max, Min;
}tree[N*4];
int n, q, x, y, Max, Min;

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {
		scanf("%d", &tree[k].Max);
		tree[k].Min = tree[k].Max;
		return;
	}
	
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	tree[k].Max = max(tree[2*k].Max,tree[2*k+1].Max);
	tree[k].Min = min(tree[2*k].Min,tree[2*k+1].Min);
}

void ask(int k, int l,int r) {
	if(x <= l && r <= y) {
		Max = max(Max, tree[k].Max);
		Min = min(Min, tree[k].Min);
		return;
	}
	
	int mid = (l + r) / 2;
	if(x <= mid) ask(2*k, l, mid);
	if(y > mid) ask(2*k+1, mid+1, r);
}

int main() {
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	for(int i = 1;i <= q; i++) {
		scanf("%d %d", &x, &y);
		Max = -1; Min = 10000001;
		ask(1, 1, n);
		printf("%d\n", Max-Min);
	}
}

