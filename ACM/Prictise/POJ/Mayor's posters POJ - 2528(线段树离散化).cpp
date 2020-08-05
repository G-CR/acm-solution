#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 200005;

struct Tree{
	int l,r;
	int val;
} tree[N*4+5];

int ans,Left[N],Right[N],lisan[N];
bool vis[N];

void build(int k, int le, int ri) {
	tree[k].l = le; tree[k].r = ri;
	if(le == ri) {
		tree[k].val = 0; return;
	}
	int mid = (le + ri) / 2;
	build(2*k, le, mid);
	build(2*k+1, mid+1, ri);
	tree[k].val = 0;
}

void spread(int k) {
	if(tree[k].val == 0) return;
	tree[2*k].val = tree[k].val;
	tree[2*k+1].val = tree[k].val;
	tree[k].val = 0;
}

void change_interval(int k, int le, int ri, int v) {
	if(le <= tree[k].l && ri >= tree[k].r) {
		tree[k].val = v; return;
	}
	spread(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if(le <= mid) change_interval(2*k, le, ri, v);
	if(ri > mid) change_interval(2*k+1, le, ri, v);
}

void ask(int k, int le, int ri) {
	if(tree[k].val && !vis[tree[k].val]) {
		ans++;
		vis[tree[k].val] = 1;
		return;
	}
	if(le == ri) return;
	spread(k);
	int mid = (le + ri) / 2;
	ask(2*k, le, mid);
	ask(2*k+1, mid+1, ri);
}

int main() {
	int T,n;
	scanf("%d", &T);
	
	while(T--) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 0;i < n; i++) {
			scanf("%d %d", &Left[i], &Right[i]);
			lisan[cnt++] = Left[i];
			lisan[cnt++] = Right[i];
		}
		sort(lisan, lisan+cnt);
		
		int t = unique(lisan, lisan+cnt) - lisan;
		cnt = t;
		for(int i = 1;i < t; i++) {
			if(lisan[i] - lisan[i-1] > 1) {
				lisan[cnt++] = lisan[i-1]+1;
			}
		}
		sort(lisan, lisan+cnt);
		build(1,1,cnt);
		for(int i = 0;i < n; i++) {
			int x = lower_bound(lisan, lisan+cnt, Left[i]) - lisan+1;
			int y = lower_bound(lisan, lisan+cnt, Right[i]) - lisan+1;
			change_interval(1, x, y, i+1);
		}
		ans = 0;
		ask(1,1,cnt);
		printf("%d\n", ans);
	}
}