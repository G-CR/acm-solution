#include <bits/stdc++.h>
using namespace std;
const int N = 50005;

struct Tree {
	int zy, zz;
	int l, r;
}tree[N*4];
stack <int> sta;
int n, m, x;
char c;

void build(int k, int l, int r) {
	tree[k].l = l; tree[k].r = r;
	tree[k].zy = n+1; tree[k].zz = 0;
	if(l == r) return;
	
	int mid = (l + r) / 2;
	build(2*k, l, mid);
	build(2*k+1, mid+1, r);
}

void change_zz(int k, int t, int p) {
	if(tree[k].l == tree[k].r) {
		tree[k].zz = t;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if(p <= mid) change_zz(2*k, t, p);
	else change_zz(2*k+1, t, p);
	
	tree[k].zz = max(tree[2*k].zz, tree[2*k+1].zz);
}

void change_zy(int k, int t, int p) {
	if(tree[k].l == tree[k].r) {
		tree[k].zy = t;
		return;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if(p <= mid) change_zy(2*k, t, p);
	else change_zy(2*k+1, t, p);
	
	tree[k].zy = min(tree[2*k].zy, tree[2*k+1].zy);
}

int ask_zz(int k, int l, int r) {
	if(l <= tree[k].l && tree[k].r <= r) {
		return tree[k].zz;
	}
	
	int res = 0;
	int mid = (tree[k].l + tree[k].r) / 2;
	if(l <= mid) res = max(res, ask_zz(2*k, l, r));
	if(mid < r) res = max(res, ask_zz(2*k+1, l, r));
	return res;
}

int ask_zy(int k, int l, int r) {
	if(l <= tree[k].l && tree[k].r <= r) {
		return tree[k].zy;
	}
	
	int res = 50005;
	int mid = (tree[k].l + tree[k].r) / 2;
	if(l <= mid) res = min(res, ask_zy(2*k, l, r));
	if(mid < r) res = min(res, ask_zy(2*k+1, l, r));
	
	return res;
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		while(!sta.empty()) sta.pop();
		build(1, 1, n);
		while(m--) {
			scanf(" %c", &c);
			if(c == 'R') {
				x = sta.top(); sta.pop();
				change_zz(1, 0, x);
				change_zy(1,n+1, x);
			}
			
			else {
				scanf("%d", &x);
				if(c == 'D') {
					sta.push(x);
					change_zz(1, x, x);
					change_zy(1, x, x);
				}
				else if(c == 'Q') {
					int Left = ask_zz(1, 1, x);
					int Right = ask_zy(1, x, n);
					if(Left == Right) puts("0");
					else printf("%d\n", Right - Left - 1);
				}
			}
		}
		
	}
}

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m,x;
	char c;
	while(scanf("%d %d", &n, &m)) {
		stack <int> sk;
		set <int> st;
		st.insert(0); st.insert(n+1);
		while(m--) {
			getchar();
			scanf(" %c", &c);
			if(c == 'R') st.erase(sk.top()),sk.pop();
			else {
				scanf("%d",&x);
				if(c=='D') st.insert(x),sk.push(x);
				else if(st.find(x)!=st.end()) puts("0");
				else {
					set<int> ::iterator l, r;
					l=st.lower_bound(x),r=st.upper_bound(x);
					printf("%d\n",*r-*--l-1);
				}
			}
		}
	}
	return 0;
}
*/