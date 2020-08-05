// https://ac.nowcoder.com/acm/contest/5891/C
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mod = 1e9+7;
int n, m;
int dist[1000006];
bool vis[1000006];
vector <int> g[2000006];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

struct node1 {
	int u, v;
} edge[2000006];

struct node {
	int pos, step;
	node(int p, int s) {pos = p;step = s;}
};

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &edge[i].u, &edge[i].v);
		g[edge[i].u].push_back(edge[i].v);
		g[edge[i].v].push_back(edge[i].u);
	}
	
	queue<node> q;
	q.push(node(1,0));
	while(!q.empty()) {
		node t = q.front(); q.pop();
//		printf("%d ", t.pos); getchar();
		dist[t.pos] = t.step;
		for(auto i: g[t.pos]) {
			if(vis[i]) continue;
			vis[i] = 1;
			q.push(node(i, t.step+1));
		}
	}
	
	long long ans = 0;
	for(int i = 2;i <= n; i++) {
		ans = (ans + qpow(2, dist[i])) % mod;
	}
	printf("%lld\n", (ans+mod)%mod);
}