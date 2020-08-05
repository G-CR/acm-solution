#include <bits/stdc++.h>
using namespace std;

string soft_ware[30004];
vector <int> g[30004], ans;
unordered_map <string, int> mp;
priority_queue <int, vector<int>, greater<int> > q;
int n, m, _, in[30004];

int main() {
	scanf("%d", &_);
	for(int cas = 1;cas <= _; cas++) {
		scanf("%d %d", &n, &m);
		
		memset(in, 0, sizeof(in));
		for(int i = 1;i <= n; i++) g[i].clear();
		ans.clear(); mp.clear();
		
		for(int i = 1;i <= n; i++) cin >> soft_ware[i];
		sort(soft_ware+1, soft_ware+1+n);
		for(int i = 1;i <= n; i++) mp[soft_ware[i]] = i;
		for(int i = 1;i <= m; i++) {
			string u, v;
			cin >> u >> v;
			in[mp[v]]++;
			g[mp[u]].push_back(mp[v]);
		}
		for(int i = 1;i <= n; i++) {
			if(in[i] == 0) q.push(i);
		}
		
		while(!q.empty()) {
			int t = q.top(); q.pop();
			if(in[t] == 0) ans.push_back(t);
			int len = g[t].size();
			for(int i = 0;i < len; i++) {
				int k = g[t][i];
				in[k]--;
				if(in[k] == 0) q.push(k);
			}
		}
		printf("Case #%d:\n", cas);
		int cnt = ans.size();
		if(cnt != n) puts("Impossible");
		else {
			for(int i = 0;i < cnt; i++) {
				cout << soft_ware[ans[i]] << endl;
			}
		}
	}
}