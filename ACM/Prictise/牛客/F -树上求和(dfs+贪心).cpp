// https://ac.nowcoder.com/acm/contest/5986/F
#include <bits/stdc++.h>
using namespace std;

int u, v, n;
vector <long long> g[100005], ans;

long long dfs(int u, int v) {
	long long sum = 1;
	int cnt = g[u].size();
	for(int i = 0; i < cnt; i++) {
		if(g[u][i] == v) continue;
		sum += dfs(g[u][i], u);
	}
//	cout << u << " " << v << " " << sum*(n-sum) << endl;
	ans.push_back(sum*(n-sum));
	return sum;
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1;i < n; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1);
	sort(ans.begin(), ans.end());
	long long res = 0;
	int cnt = ans.size();
//	for(int i = 1;i < cnt; i++) printf("%d ", ans[i]); puts("");
	for(int i = 1;i < cnt; i++) res += (n-i)*ans[i];
	printf("%lld\n", res);
}