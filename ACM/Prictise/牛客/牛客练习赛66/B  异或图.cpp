#include <bits/stdc++.h>
using namespace std;

int n, q, x, y, a[1000006], k;
bool vis[2000006];

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		vis[a[i]] = 1;
	}
	while(q--) {
		scanf("%d %d %d", &k, &x, &y);
		if(a[x] == a[y]) {
			int t = a[x]^k;
			if(vis[t]) puts("2");
			else puts("-1");
		}
		else {
			int t = a[x]^a[y];
			if(t == k) puts("1");
			else puts("-1");
		}
	}
}