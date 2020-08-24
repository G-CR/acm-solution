#include <bits/stdc++.h>
using namespace std;

int _, n, p, a, sum[100005];
map <int, bool> vis;

int main() {
	scanf("%d", &_);
	while(_--) {
		vis.clear();
		int ans = 0;
		scanf("%d %d", &n, &p);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a); a %= p;
			if(a == 0) {
				vis.clear();
				sum[i] = 0;
				ans++;
				continue;
			}
			sum[i] = (sum[i-1]+a)%p;
			if(vis[sum[i]] || sum[i] == 0) {
				ans++;
				vis.clear();
				sum[i] = 0;
			}
			else vis[sum[i]] = 1;
		}
		
		printf("%d\n", ans);
	}
}