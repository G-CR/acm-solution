#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e3+9;
int n, cnt;
int x[maxn<<2|1], sum[maxn], res[maxn];

void build() {
	memset(x, -1, sizeof(x));
	memset(sum, 0, sizeof(sum));
}

void pushdown(int k) {
	if(x[k] != -1) {
		x[k<<1] = x[k<<1|1] = x[k];
		x[k] = -1;
	}
}

void up(int L, int R, int v, int l, int r, int k) {
	if(L <= l && r <= R) {
		x[k] = v;
		return;
	}
	pushdown(k);
	int mid = (l+r) >> 1;
	if(L <= mid) up(L, R, v, l, mid, k<<1);
	if(R > mid) up(L, R, v, mid+1, r, k<<1|1);
}

void qu(int l, int r, int k) {
	if(l == r) {
		res[++cnt] = x[k];
		return;
	}
	pushdown(k);
	int mid = (l+r) >> 1;
	qu(l, mid, k<<1);
	qu(mid+1, r, k<<1|1);
}

int main() {
	while(~scanf("%d", &n)) {
		build();
		cnt = 0;
		int l, r, c;
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d", &l, &r, &c); l++;
			if(l > r) continue;
			up(l, r, c, 1, 8000, 1);
		}
		qu(1, 8000, 1);
		for(int i = 1;i <= cnt; i++) {
			if(i==1||res[i] != res[i-1]) if(res[i] != -1) sum[res[i]]++;
		}
		
		for(int i = 0;i < 8000; i++) {
			if(sum[i]) printf("%d %d\n", i, sum[i]);
		}
		puts("");
	}
}



// https://vjudge.net/problem/ZOJ-1610
#include<bits/stdc++.h>
using namespace std;

struct Tree{
	int l, r, val;
}tree[8005*4];

int ans[8005],x1,x2,c,last,n;

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r;
	if(l == r) {tree[k].val = -1; return;}
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
	tree[k].val = -1;
}

void down(int k) {
	if(tree[k].val == -1) return;
	tree[2*k].val = tree[2*k+1].val = tree[k].val;
	tree[k].val = -1;
}

void change_interval(int k) {
	if(x1 <= tree[k].l && tree[k].r <= x2) { 
		tree[k].val = c; return;
	}
	
	down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if(x1 <= mid) change_interval(2*k);
	if(x2 > mid) change_interval(2*k+1);
}

void ask(int k, int l, int r) {
	if(l == r) {
		if(tree[k].val != -1 && tree[k].val != last) {
			ans[tree[k].val]++;
		}
		last = tree[k].val;
		return;
	}
	down(k);
	int mid = (l + r) / 2;
	ask(2*k, l, mid);
	ask(2*k+1, mid+1, r);
}

int main() {
	while(~scanf("%d", &n)) {
		memset(ans,0,sizeof(ans));
		last = -1;
		build(1, 1, 8000);
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d", &x1, &x2, &c); x1++;
			change_interval(1);
		}
		ask(1,1,8000);
		
		for(int i = 0;i <= 8000; i++) {
			if(ans[i]) printf("%d %d\n", i, ans[i]);
		}
		puts("");
	}
}
