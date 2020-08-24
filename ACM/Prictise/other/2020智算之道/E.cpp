#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll a[N];

int head[N], top = 1, fa[N][33], deep[N], color[N];

struct EDGE{
	int v, next;
} e[2*N];

int n, m, s;

void add_edge(int u,int v){
	e[top].v = v;
	e[top].next = head[u];
	head[u] = top++;
}

void dfs(int u,int f){
	fa[u][0] = f;
	for (int i = 1; i < 32;i++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	deep[u] = deep[f] + 1;
	for (int i = head[u]; i; i = e[i].next){
		int to = e[i].v;
		if(to!=f){
			dfs(to, u);
		}
	}
}

int lca(int x,int y){
	if(deep[x]<deep[y]){
		swap(x, y);
	}
	int d = deep[x] - deep[y];
	for (int i = 0; i < 32;i++){
		if(d&1){
			x = fa[x][i];
		}
		d = d / 2;
	}
	if(x==y){
		return x;
	}
	for (int i = 31; i >= 0;i--){
		int tox = fa[x][i];
		int toy = fa[y][i];
		if(tox==0){
			continue;
		}
		if(tox!=toy){
			x = tox;
			y = toy;
		}
	}
	return fa[x][0];
}

inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

vector<int> v;

void dfs1(int u, int f) {
	v.push_back(u);
	for (int i = head[u]; i; i = e[i].next) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u);
	}
}

ll work() {
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int lc = lca(v[i], v[j]);
			while(lc && color[lc] == 0) lc = fa[lc][0];
			ans += a[lc];
		}
	}
	return ans;
}





int main() {
	ll n, m;
	n = read(), m = read();
	for (int i = 2; i <= n; i++) {
		int x; x =  read();
		add_edge(i, x);
		add_edge(x, i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		a[i] =  read();
		color[i] = 0;
	}
	while (m--) {
		char op;
		ll u, w;
		scanf(" %c", &op);
		if (op == 'Q') {
			v.clear();
			u = read();
			dfs1(u, fa[u][0]);
			printf("%lld\n", work());
		} else if (op == 'M') {
			u = read();
			w = read();
			a[u] = w;
		} else {
			u = read();
			if (color[u]) {
				color[u] = 0;
			} else {
				color[u] = 1;
			}
		}

	}
}