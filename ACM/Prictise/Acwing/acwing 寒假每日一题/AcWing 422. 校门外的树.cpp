#include <bits/stdc++.h>
using namespace std;

int len, m;
bool vis[10004];

int main() {
	scanf("%d %d", &len, &m);
	int l, r;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &l, &r);
		for(int j = l;j <= r; j++) {
			vis[j] = 1;
		}
	}
	
	int ans = 0;
	for(int i = 0;i <= len; i++) {
		if(!vis[i]) ans++;
	}
	
	printf("%d\n", ans);
}