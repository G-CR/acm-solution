#include<bits/stdc++.h>
using namespace std;

struct node {
	int l, r, job, lazy;
	vector <int> son;
} tree[50004];
int _, n, m, times;
bool notroot[50004];
char cas;

void dfs(int rt) {
	tree[rt].l = ++times;
	tree[rt].job = tree[rt].lazy = -1;
	for(auto s: tree[rt].son) dfs(s);
	tree[rt].r = times;
}

void down(int rt) {
	if(tree[rt].lazy == -1) return;
	for(auto s: tree[rt].son) {
		tree[s].job = tree[s].lazy = tree[rt].lazy;
	}
	tree[rt].lazy = -1;
}

int query(int x, int rt) {
	if(x == rt) return tree[x].job;
	down(rt);
	for(auto s : tree[rt].son) {
		if(tree[s].l <= tree[x].l && tree[x].l <= tree[s].r)
			return query(x, s);
	}
}

void update(int x, int y, int rt) {
	if(x == rt) {
		tree[x].job = tree[x].lazy = y;
		return;
	}
	down(rt);
	for(auto s: tree[rt].son) {
		if(tree[s].l <= tree[x].l && tree[x].r <= tree[s].r)
			update(x, y, s);
	}
}

int main() {
	scanf("%d", &_);
	for(int cnt = 1;cnt <= _; cnt++) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			tree[i].son.clear();
			notroot[i] = 0;
		} 
		for(int i = 1;i < n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			tree[v].son.push_back(u);
			notroot[u] = 1;
		}

		int root;
		for(int i = 1;i <= n; i++) {
			if(!notroot[i]) {root = i; break;}
		}
		dfs(root);

		scanf("%d", &m);
		printf("Case #%d:\n", cnt);
		while(m--) {
			int x, y;
			scanf(" %c %d", &cas, &x);
			if(cas == 'C') printf("%d\n", query(x, root));
			else {
				scanf("%d", &y);
				update(x, y, root);
			}
		}
	}
}