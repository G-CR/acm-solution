#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005], fa[200005], num[200005];
vector <int> g[200005], ans;

int fin(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		fa[i] = i;
		num[i] = 1;
	}
	int u, v;
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		if(a[u] == a[v]) {
			int fu = fin(u);
			int fv = fin(v);
			if(fu != fv) {
				fa[fv] = fu;
				num[fu] += num[fv];
				num[fv] = num[fu];
			}
		}
	}
	
	int Max = -1;
	for(int i = 1;i <= n; i++) {
		int fnow = fin(i);
		if(num[fnow] > Max) {
			Max = num[fnow];
			ans.clear();
			ans.push_back(i);
		}
		else if(num[fnow] == Max) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for(int i: ans) printf("%d ", i); puts("");
}