#include <bits/stdc++.h>
using namespace std;

int _, n;
struct node {
	int a, b, c;
} relation[2000006];
int fa[2000006], fin[2000006];

int find(int x) {
	if(fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		bool ok = 1;
		scanf("%d", &n);
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d", &relation[i].a, &relation[i].b, &relation[i].c);
			fin[++cnt] = relation[i].a;
			fin[++cnt] = relation[i].b;
		}
		
		sort(fin+1, fin+1+cnt);
		cnt = unique(fin+1, fin+1+cnt)-fin-1;
		for(int i = 1;i <= cnt; i++) fa[i] = i;
		for(int i = 1;i <= n; i++) {
			relation[i].a = lower_bound(fin+1, fin+1+cnt, relation[i].a) - fin;
			relation[i].b = lower_bound(fin+1, fin+1+cnt, relation[i].b) - fin;
			
			int u = find(relation[i].a);
			int v = find(relation[i].b);
			
			if(relation[i].c == 1) {
				if(u != v) fa[u] = v;
			}
			else {
				if(u == v) ok = 0;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}

/*
// 超时代码 没有离散化直接用map并查集
#include <bits/stdc++.h>
using namespace std;

int _, n, c;
int a, b;
map <int, int> fa;
map < pair<int, int>, bool> bad;
bool ok;

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		fa.clear(); bad.clear();
		scanf("%d", &n);
		while(n--) {
			ok = 1;
			scanf("%d %d %d", &a, &b, &c);
			if(fa[a] == 0) fa[a] = a;
			if(fa[b] == 0) fa[b] = b;
			long long u = find(a);
			long long v = find(b);
			
			if(c == 1) {
				if(bad[make_pair(u, v)]) ok = 0;
				else {
					fa[u] = v;
				}
			}
			else {
				if(u == v) ok = 0;
				else {
					bad[make_pair(u, v)] = 1;
					bad[make_pair(u, v)] = 1;
				}
			}
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}
*/