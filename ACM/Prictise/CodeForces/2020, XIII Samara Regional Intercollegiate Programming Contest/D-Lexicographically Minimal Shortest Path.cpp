#include <bits/stdc++.h>
using namespace std;

int n, m, dis[200005];
vector <pair<int, char> > g[200005];
int pre[200005];

void bfs() {
	bool vis[200005]; memset(vis, 0, sizeof(vis));
	queue <int> q; while(!q.empty()) q.pop();
	q.push(n); vis[n] = 1; dis[n] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto i: g[now]) {
			int t = i.first;
			if(vis[t]) continue;
			vis[t] = 1;
			dis[t] = dis[now]+1;
			q.push(t);
		}
	}
}

char findm(vector <int> fa) {
	char minc = 'z';
	for(auto i: fa) {
		for(auto j: g[i]) {
			int jf = j.first; char js = j.second;
			if(dis[i] == dis[jf]+1) {
				minc = min(minc, js);
			}
		}
	}
	return minc;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; ++i) {
		int u, v; char c;
		scanf("%d %d %c", &u, &v, &c);
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}
	
	bfs();
	
	vector <int> fa; fa.push_back(1);
	string ans = ""; pre[1] = -1;
	for(int floors = 1;floors <= dis[1]; floors++) {
		ans += minc;
		vector <int> tmp; tmp.clear();
		for(auto i: fa) {
			for(auto j: g[i]) {
				int jf = j.first; char js = j.second;
				if(dis[i] == dis[jf]+1 && js == minc) {
					if(pre[jf]==0) pre[jf] = i;
					tmp.push_back(jf);
				}
			}
			
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		fa = tmp;
	}
	int k = n;
	vector <int> res;
	while(k!=-1) {
		res.push_back(k);
		k = pre[k];
	} 
	int cnt = res.size()-1;
	printf("%d\n", cnt);
	for(int i = cnt;i >= 0; i--) printf("%d ", res[i]); puts("");
	cout << ans << endl;
}