#include <bits/stdc++.h>
using namespace std;

int _, n, m, fa[100005];
struct node {
	int id;
	long long b;
} city[100005];
vector <int> g[100005];
bool vis[100005];
bool cmp(node a, node b) {return a.b > b.b;}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			vis[i] = 0;
			fa[i] = i;
			g[i].clear();
		}
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &city[i].b);
			city[i].id = i;
		}
		for(int i = 1;i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		sort(city+1, city+1+n, cmp);
		int cnt = 1;
		long long h = city[1].b;
		long long ans = 0;
		vis[city[1].id]=1;
		for(int i = 2;i <= n; i++) {
			long long cha = h-city[i].b;
			ans += cnt * cha;
//			cout << "cnt = " << cnt << endl;
			vis[city[i].id] = 1;
			for(int j: g[city[i].id]) {
				int u = find(j), v = find(city[i].id);
				if(vis[j]&&u!=v) {
					cnt--;
					fa[v] = u;
				}
			}
			cnt++;
			h = city[i].b;
		}
//		cout << "cnt = " << cnt << endl;
		ans += cnt*h;
		
		printf("%lld\n", ans);
	}
}