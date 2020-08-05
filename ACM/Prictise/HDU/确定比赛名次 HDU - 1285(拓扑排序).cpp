#include <bits/stdc++.h>
using namespace std;

int n, m;
int in[505];
priority_queue <int, vector<int>, greater<int> > q;
vector<int> g[505];

int main() {
	while(~scanf("%d %d", &n, &m)) {
		memset(in, 0, sizeof(in));
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n; i++) g[i].clear();
		
		for(int i = 1;i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			in[v]++;
			g[u].push_back(v);
		}
		
		for(int i = 1;i <= n; i++) if(in[i] == 0) q.push(i);
		vector <int> ans; ans.clear();
		while(!q.empty()) {
			int u = q.top(); q.pop();
			ans.push_back(u);
			for(int i = 0;i < g[u].size(); i++) {
				int v = g[u][i];
				in[v]--;
				if(in[v] == 0) q.push(v);
			}
		}
		
		for(int i = 0;i < ans.size(); i++) {
			printf("%d", ans[i]);
			if(i != ans.size()-1) printf(" ");
			else puts("");
		}
	}
}