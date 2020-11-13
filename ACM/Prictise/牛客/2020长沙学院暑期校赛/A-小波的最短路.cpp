// https://ac.nowcoder.com/acm/contest/7697#question
#include <bits/stdc++.h>
#define inf 1e18
#define pii pair<long long, long long>
using namespace std;
const int maxn = 1e5+7;
 
long long n, m, s, t;
long long d[maxn], vis[maxn];
vector<pii>E[maxn];
void init() {
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
}
void Dijkstra() {
	d[s] = 0;
	priority_queue<pii> Q;
	Q.push({-d[s],s});
	while(!Q.empty()) {
		int now = Q.top().second;
		Q.pop(); if(vis[now]) continue;
		vis[now] = 1;
		for(int j = 0; j < E[now].size(); j++){
			int v = E[now][j].first;
			if(d[v] > d[now]+E[now][j].second) {
				d[v] = d[now]+E[now][j].second;
				Q.push({-d[v],v});
			}
		}
	}
}
 
int main() {
	long long ans = 0;
	scanf("%lld %lld %lld",&n,&m,&s);
	init();
	int a, b, x;
	while(m--) {
		scanf("%d %d %d",&a,&b,&x);
		E[a].push_back({b,x});
		E[b].push_back({a,x});
	}
	Dijkstra();
	ans += d[1];
	 
	s = 1;
	init();
	Dijkstra();
	ans += d[n];
	 
	printf("%lld\n", ans);
	return 0;
}