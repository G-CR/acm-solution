#include <bits/stdc++.h>
using namespace std;

int _, n, m, t, u, v;
map <int, int> in;
vector <int> g[200005], mp[200005], poi;
bool vis[200005];
queue <int> q;
int main() {
	scanf("%d", &_);
	while(_--) {
		in.clear();
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) g[i].clear(), mp[i].clear();
		for(int i = 1;i <= m; i++) {
			scanf("%d %d %d", &t, &u, &v);
			if(t == 1) {
				g[u].push_back(v);
				in[v]++;
			}
			else {
				mp[u].push_back(v);
				mp[v].push_back(u);
			}
		}
		int num = 0;
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n; i++) if(in[i] == 0) q.push(i), num++;
		vector <pair<int, int> > ans; ans.clear();
		
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(auto i: g[u]) {
				ans.push_back(make_pair(u, i));
				in[i]--;
				if(in[i] == 0) q.push(i), num++;
			}
			for(auto i:mp[u]) {
				if(vis[i]) continue;
				ans.push_back(make_pair(u, i));
			}
			vis[u] = 1;
		}
//		cout << num << endl;
		if(n != num) {puts("NO"); continue;} 
		puts("YES");
		for(auto i: ans) {
			printf("%d %d\n", i.first, i.second);
		}
	}
}