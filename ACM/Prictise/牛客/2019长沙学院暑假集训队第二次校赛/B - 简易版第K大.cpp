#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;

struct node {
	int l,r,num;
} tree[4*N];

int a[N],key[N];

void build(int l,int r,int k) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {
		tree[k].num = a[l];
		return;
	}
	int m = (l+r)/2;
	build(l, m, 2*k);
	build(m+1, r, 2*k+1);
	tree[k].num = tree[2*k].num + tree[2*k+1].num;
}

int ask_point(int p2,int k) {
	if(tree[k].l == tree[k].r) return tree[k].l;
	
	if(p2 > tree[2*k].num) {
		p2 -= tree[2*k].num;
		ask_point(p2, 2*k+1);
	}
	
	else {
		ask_point(p2, 2*k);
	}
}

void change_point(int pre,int change,int k) {
	if(tree[k].l == pre && pre == tree[k].r) {
		tree[k].num += change;
		return;
	}
	tree[k].num += change;
	int m = (tree[k].l + tree[k].r)/2;
	if(pre > m) change_point(pre, change, 2*k+1);
	else change_point(pre, change, 2*k);
}

int main() {
	int n,q;
	scanf("%d %d", &n, &q);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &key[i]);
		a[key[i]]++;
	}
	build(1, N, 1);
	int p1,p2,p3;
	while(q--) {
		scanf("%d", &p1);
		if(p1 == 1) {
			scanf("%d", &p2);
			printf("%d\n", ask_point(p2,1)); 
		}
		else {
			scanf("%d %d", &p2, &p3);
			change_point(key[p2],-1,1);
			change_point(p3,1,1);
			key[p2] = p3; //////////////////
		}
	}
}