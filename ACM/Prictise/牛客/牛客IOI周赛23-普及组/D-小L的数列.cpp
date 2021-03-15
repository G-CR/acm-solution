#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int _, n;
int a[maxn+7], num[maxn];
bool isnot[maxn+7];
vector <int> g[maxn+7];

void getys() {
	for(int i = 2;i <= maxn; i++) {
		if(!isnot[i]) {
			for (int j = i; j <= maxn; j += i) {
				isnot[j] = true;
				g[j].push_back(i);
			}
		}
	}
}

int dfs(int pos) {
	if(pos == 0) return 1;
	int res = 1;
	for(int i = 0;i < g[a[pos]].size(); i++) res = max(res, num[g[a[pos]][i]]+1);
	for(int i = 0;i < g[a[pos]].size(); i++) num[g[a[pos]][i]] = res;
	return max(dfs(pos-1), res);
}

int main() {
	getys();
	scanf("%d", &_);
	while(_--) {
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		printf("%d\n", dfs(n));
	}
}