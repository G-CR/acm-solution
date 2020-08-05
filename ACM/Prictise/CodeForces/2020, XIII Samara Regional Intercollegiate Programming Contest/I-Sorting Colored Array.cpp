#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
int c[200005];
vector <long long> g[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %d", &a[i], &c[i]);
		g[c[i]].push_back(a[i]);
	}
	
	
	bool ok2 = 1;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j < g[i].size(); j++) {
			if(g[i][j] < g[i][j-1]) {ok2 = 0; break;}
		}
		if(!ok2) break;
	}
	
	if(!ok2) puts("NO");
	else puts("YES");
}