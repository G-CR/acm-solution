#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> g[103];
int in[103];

int main() {
	scanf("%d", &n);
	for(int u = 1; u <= n; u++) {
		int v;
		while(~scanf("%d", &v) && v) {
			g[u].push_back(v);
			in[v]++;
		}
	}
	
	queue <int> q;
	for(int i = 1;i <= n; i++) {
		if(in[i] == 0) q.push(i);
	}
	vector <int> ans;
	while(!q.empty()) {
		int t = q.front(); q.pop();
		printf("%d ", t);
		for(int i = 0;i < g[t].size(); i++) {
			int now = g[t][i];
			in[now]--;
			if(in[now] == 0) q.push(now);
		}
	}
}