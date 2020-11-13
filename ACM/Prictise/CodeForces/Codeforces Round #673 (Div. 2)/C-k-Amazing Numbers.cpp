#include <bits/stdc++.h>
using namespace std;

int _, n, a[300005];
vector <int> g[300005];
int ans[300005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) g[i].clear();
		for(int i = 1;i <= n; i++) g[i].push_back(0);
		for(int i = 1;i <= n; i++) {
			ans[i] = 1e9;
			scanf("%d", &a[i]);
			g[a[i]].push_back(i);
		}
		for(int i = 1;i <= n; i++) g[i].push_back(n+1);
		
		for(int i = n; i >= 1; i--) {
			int mlen = 0;
			for(int j = 1;j < g[i].size(); j++) {
				mlen = max(mlen, g[i][j]-g[i][j-1]);
			}
			if(mlen <= n) ans[mlen] = i;
		}
		
		int pos = 1;
		for(int i = 1;i <= n; i++) {
			pos = i;
			if(ans[i] != -1) break;
		}
		
		for(int i = pos+1; i <= n; i++) {
			ans[i] = min(ans[i-1], ans[i]);
		}
		
		for(int i = 1;i <= n; i++) {
			printf("%d ", ans[i]==1e9?-1:ans[i]);
		}
		puts("");
	}
}