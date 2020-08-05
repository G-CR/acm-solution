#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[200005];
struct node {
	int ok;
	int num;
}vis[200005];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) vis[i].ok = 0;
		int ans = 200005;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			if(vis[a[i]].ok) {
				ans = min(ans, i-vis[a[i]].num+1);
				vis[a[i]].num = i;
			}
			else {
				vis[a[i]].ok = 1;
				vis[a[i]].num = i;
			}
		}
		if(ans == 200005) ans = -1;
		printf("%d\n", ans);
	}
}