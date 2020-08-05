#include <bits/stdc++.h>
using namespace std;

int _, k, cas;
long long pre[40];
bool vis[40];

int main() {
	pre[0] = 1;
	for(int i = 1;i <= 32; i++) {
		pre[i] = pre[i-1]*3;
	}
	scanf("%d", &_);
	while(_--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &k);
		int cnt = 0;
		while(k) {
			if(k&1) vis[cnt] = 1;
			cnt++;
			k >>= 1;
		}
		
		long long ans = 0;
		for(int i = 0;i <= 32; i++) {
			if(vis[i]) ans += pre[i];
		}
		printf("Case #%d: ", ++cas);
		printf("%lld\n", ans);
	}
}