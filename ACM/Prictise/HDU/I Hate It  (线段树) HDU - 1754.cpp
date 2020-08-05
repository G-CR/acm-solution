#include <bits/stdc++.h>
using namespace std;


int N, M, a, b, ans;
char c;

struct node {
	int l, r, sum;
}tree[4000100];

void build(int k,int left,int right) {
	tree[k].l = left; tree[k].r = right;
	if(left == right) {
		scanf("%d", &tree[k].sum);
		return;
	}
	
	int mid = (left + right) / 2;
	build(2*k, left, mid);
	build(2*k+1, mid+1, right);
	
	tree[k].sum = max(tree[2*k].sum, tree[2*k+1].sum);
}

void change_point(int k) {
	if(tree[k].l == tree[k].r) {
		tree[k].sum = b;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(a <= mid) change_point(2*k);
	else change_point(2*k+1);
	
	tree[k].sum = max(tree[2*k].sum, tree[2*k+1].sum);
}

void ask_interval(int k) {
	if(a <= tree[k].l && tree[k].r <= b) {
		ans = max(ans, tree[k].sum);
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if(a <= mid) ask_interval(2*k);
	if(mid < b) ask_interval(2*k+1);
}

int main() {
	while(~scanf("%d %d", &N, &M)) {
		build(1, 1, N);
			while(M--) {
			scanf(" %c %d %d", &c, &a, &b);
			if(c == 'Q') {
				ask_interval(1);
				printf("%d\n", ans);
				ans = 0;
			} else {
				change_point(1);
			}
		}
	} 
	
}