#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005], ans[100005];
bool vis[100005];
vector <int> v;

void dfs(int pos) {
	if(vis[pos]) return;
	vis[pos] = 1;
	v.push_back(a[pos]);
	dfs(a[pos]);
}

void nice() {
	int len = v.size(), x;
	for(int i = 0;i < len; i++) {
		if(((long long)i*(k%len))%len == 1) {
			x = i; break;
		}
	}
	
	for(int i = 0;i < v.size(); i++) {
		ans[v[i]] = v[(i+x)%len];
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1;i <= n; i++) {
		if(!vis[i]) {
			v.clear();
			dfs(i);
//			for(int i = 0;i < v.size(); i++) printf("%d ", v[i]); puts("");
			nice();
		}
	}
	
	for(int i = 1;i <= n; i++) printf("%d ", ans[i]); puts("");
}