#include <bits/stdc++.h>
using namespace std;
const int N = 50005*4;

struct Tree {
	int k, l, r;
	int people;
} tree[N];
int a, b, T, n, sum;
string s;

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {
		scanf("%d", &tree[k].people);
		return;
	}
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	
	tree[k].people = tree[2*k].people + tree[2*k+1].people;
}

void change_point(int k) {
	if(tree[k].l == tree[k].r) {
		if(s == "Add") tree[k].people += b;
		else if(s == "Sub") tree[k].people -= b;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(a <= mid) change_point(2*k);
	else change_point(2*k+1);
	
	tree[k].people = tree[2*k].people + tree[2*k+1].people;
}

void ask_interval(int k) {
	if(a <= tree[k].l && tree[k].r <= b) {
		sum += tree[k].people;
		return;
	}
	
	int mid = (tree[k].l + tree[k].r) / 2;
	if(a <= mid) ask_interval(2*k);
	if(b > mid) ask_interval(2*k+1);
}

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%d", &n);
		printf("Case %d:\n", p);
		build(1, 1, n);
		while(1) {
			cin >> s;
			if(s == "End") break;
			scanf("%d %d", &a, &b);
			if(s == "Add" || s == "Sub") {
				change_point(1);
			}
			if(s == "Query") {
				sum = 0;
				ask_interval(1);
				printf("%d\n", sum);
			}
		}
	}
}